#include <stdio.h>
#include <windows.h>

#define BYTE unsigned char
#define WORD unsigned long

/* 8 位*/
/* 32 位 */
/* （使字X的位向左移动一位） */
#define ROTL(x) (((x)>>7)|((x)<<1))

/* （使32位的字向左移动一个，两个或者三个字节，即8位，16位或者24位）*/
#define ROTL8(x) (((x)<<8)|((x)>>24))
#define ROTL16(x) (((x)<<16)|((x)>>16))
#define ROTL24(x) (((x)<<24)|((x)>>8))

static BYTE InCo[4]={0xB,0xD,0x9,0xE};

/* 逆换系数*/
static BYTE fbsub[256];
static BYTE rbsub[256];
static BYTE ptab[256],ltab[256];
static WORD ftable[256];
static WORD rtable[256];
static WORD rco[30];

/* 相关数据参数*/
int Nk,Nb,Nr;
BYTE fi[24],ri[24];
WORD fkey[120];
WORD rkey[120];

/*包装成一个字节字*/
static WORD pack(BYTE *b)
{ /* pack bytes into a 32-bit Word */
	return ((WORD)b[3]<<24)|((WORD)b[2]<<16)|((WORD)b[1]<<8)|(WORD)b[0];
}

/*从字打开字节*/
static void unpack(WORD a,BYTE *b)
{ /* unpack bytes from a word */
	b[0]=(BYTE)a; b[1]=(BYTE)(a>>8);
	b[2]=(BYTE)(a>>16);
	b[3]=(BYTE)(a>>24);
}

//GF(2^8)上的x乘法
static BYTE xtime(BYTE a)
{
	BYTE b = 0;
	if (a&0x80)
	    b=0x1B;
     else
		a<<=1;
	a^=b;
	b=0;
	return a;
}

static BYTE bmul(BYTE x,BYTE y)
{ 
	if (x && y)
		return ptab[(ltab[x]+ltab[y])%255];
	else
		return 0;
}

/*进行字节变换*/
static WORD SubByte(WORD a)
{
	BYTE b[4];
	unpack(a,b);
	b[0]=fbsub[b[0]];
	b[1]=fbsub[b[1]];
	b[2]=fbsub[b[2]];
	b[3]=fbsub[b[3]];
	return pack(b);
}

static BYTE product(WORD x,WORD y)
{ /* dot product of two 4-byte arrays */
	BYTE xb[4],yb[4];
	unpack(x,xb);
	unpack(y,yb);
	return bmul(xb[0],yb[0])^bmul(xb[1],yb[1])^bmul(xb[2],yb[2])^bmul(xb[3],yb[3]);
}

/*列混合的逆变换*/
static WORD InvMixCol(WORD x)
{ /* matrix Multiplication */
	WORD y,m;
	BYTE b[4];
	m=pack(InCo);
	b[3]=product(m,x);
	m=ROTL24(m);
	b[2]=product(m,x);
	m=ROTL24(m);
	b[1]=product(m,x);
	m=ROTL24(m);
	b[0]=product(m,x);
	y=pack(b);
	return y;
}

/*字节逆变换*/
BYTE ByteSub(BYTE x)
{
	BYTE y=ptab[255-ltab[x]];
	x=y;
	x=ROTL(x); /* multiplicative inverse */
	y^=x;
	x=ROTL(x);
	y^=x;
	x=ROTL(x);
	y^=x;
	x=ROTL(x);
	y^=x;
	y^=0x63;
	return y;
}

/*初始化*/
void gentables(void)
{ //初始化矩阵
	int i;
	BYTE y,b[4];
	ltab[0]=0;
	ptab[0]=1;
	ptab[1]=3;
	ltab[1]=0;
	ltab[3]=1;
	for (i=2;i<256;i++)
	{
		ptab[i]=ptab[i-1]^xtime(ptab[i-1]);
		ltab[ptab[i]]=i;
	}
	// 进行移位操作
	fbsub[0]=0x63;
	rbsub[0x63]=0;
	for (i=1;i<256;i++)
	{
		y=ByteSub((BYTE)i);
		fbsub[i]=y;
		rbsub[y]=i;
	}
	for (i=0,y=1;i<30;i++)
	{
		rco[i]=y;
		y=xtime(y);
    }
	for (i=0;i<256;i++)
	{
		y=fbsub[i];
		b[3]=y^xtime(y);
		b[2]=y;
		b[1]=y;
		ftable[i]=pack(b);
		b[0]=xtime(y);
		y=rbsub[i];
		b[3]=bmul(InCo[0],y);
		b[2]=bmul(InCo[1],y);
		b[1]=bmul(InCo[2],y);
		b[0]=bmul(InCo[3],y);
		rtable[i]=pack(b);
	}
}

/*字符串转换成十六进制数*/
void strtoHex(char *str,char *hex)
{
	char ch;
	int i=0, by = 0;
	while(i < 64 && *str)
	{
		ch = toupper(*str++);
		// the maximum key length is 32 bytes(256 bits) 最大密钥长度是256位and ， 因此最多64位十六进制数. 处理一个十六进制位.
		if(ch >= '0' && ch <= '9')
			by = (by << 4) + ch - '0';
		else if(ch >= 'A' && ch <= 'F')
			by = (by << 4) + ch - 'A' + 10;
		else
		{
			printf("key must be in hexadecimal notation\n");
			exit(0);
		} // 对非十六进制数报错

		//（以十六进制方式存储密钥）
		if(i++ & 1)
			hex[i / 2 - 1] = by & 0xff;
	}
}

/*16进制数转换成字符串*/
void hextoStr(char *hex,char *str)
{
	int i=0, by = 0;
	while(i < 32 && *hex)
	{
		by = *hex ;
		//  最大密钥长度是256位 , 因此最多64位十六进制数.处理一个十六进制位.
		by=by>>4 &0x0f;
		if(by >= 0 && by <= 9)
			*str++ = by + '0';
		else if(by >= 0x0A && by <= 0x0F)
			*str++ = by - 10 + 'A';
		by = *hex++;
		by=by &0x0f;
		if(by >= 0 && by <= 9)
			*str++ = by + '0';
		else if(by >= 0x0A && by <= 0x0F)
			*str++ = by -10 + 'A';
		i++;
	}
}
/*获得密钥*/
void gkey(int nb,int nk,char *key)
{
	int i,j,k,m,N;
	int C1,C2,C3;
	WORD CipherKey[8];
	Nb=nb;
	Nk=nk;
/* Nr is number of rounds Nr是加密的轮数*/
	if (Nb>=Nk)
		Nr=6+Nb;
	else
		Nr=6+Nk;
	C1=1;
	if (Nb<8)
	{
		C2=2;
		C3=3;
	}
	else
	{
		C2=3;
		C3=4;
	}
	for (m=j=0;j<nb;j++,m+=3)
{
		fi[m]=(j+C1)%nb;
		fi[m+1]=(j+C2)%nb;
		fi[m+2]=(j+C3)%nb;
		ri[m]=(nb+j-C1)%nb;
		ri[m+1]=(nb+j-C2)%nb;
		ri[m+2]=(nb+j-C3)%nb;
	}
	N=Nb*(Nr+1);
	for (i=j=0;i<Nk;i++,j+=4)
	{
		CipherKey[i]=pack((BYTE *)&key[j]);
	}
	for (i=0;i<Nk;i++)
		fkey[i]=CipherKey[i];
	for (j=Nk,k=0;j<N;j+=Nk,k++)
	{
		fkey[j]=fkey[j-Nk]^SubByte(ROTL24(fkey[j-1]))^rco[k];
		if (Nk<=6)
		{
			for (i=1;i<Nk && (i+j)<N;i++)
				fkey[i+j]=fkey[i+j-Nk]^fkey[i+j-1];
		}
		else
		{
			for (i=1;i<4 &&(i+j)<N;i++)
				fkey[i+j]=fkey[i+j-Nk]^fkey[i+j-1];
			if ((j+4)<N)
				fkey[j+4]=fkey[j+4-Nk]^SubByte(fkey[j+3]);
			for (i=5;i<Nk && (i+j)<N;i++)
				fkey[i+j]=fkey[i+j-Nk]^fkey[i+j-1];
		}
	}
	for (j=0;j<Nb;j++)
		rkey[j+N-Nb]=fkey[j];
	for (i=Nb;i<N-Nb;i+=Nb)
	{
		k=N-Nb-i;
		for (j=0;j<Nb;j++)
			rkey[k+j]=InvMixCol(fkey[i+j]);
	}
	for (j=N-Nb;j<N;j++)
		rkey[j-N+Nb]=fkey[j];
}

/*加密*/
void encrypt(char *buff)
{
	int i,j,k,m;
	WORD a[8],b[8],*x,*y,*t;
	for (i=j=0;i<Nb;i++,j+=4)
	{
		a[i]=pack((BYTE *)&buff[j]);
		a[i]^=fkey[i];
	}
	k=Nb;
	x=a;
	y=b;
	for (i=1;i<Nr;i++)
	{
		for (m=j=0;j<Nb;j++,m+=3)
		{
			y[j]=fkey[k++]^ftable[(BYTE)x[j]]^
				ROTL8(ftable[(BYTE)(x[fi[m]]>>8)])^
				ROTL16(ftable[(BYTE)(x[fi[m+1]]>>16)])^
				ROTL24(ftable[x[fi[m+2]]>>24]);
		}
		t=x;
		x=y;
		y=t;
	}
	for (m=j=0;j<Nb;j++,m+=3)
	{
		y[j]=fkey[k++]^(WORD)fbsub[(BYTE)x[j]]^
			ROTL8((WORD)fbsub[(BYTE)(x[fi[m]]>>8)])^
			ROTL16((WORD)fbsub[(BYTE)(x[fi[m+1]]>>16)])^
			ROTL24((WORD)fbsub[x[fi[m+2]]>>24]);
	}
	for (i=j=0;i<Nb;i++,j+=4)
	{
		unpack(y[i],(BYTE *)&buff[j]);
		x[i]=y[i]=0;
	}
	return;
}

/*解密*/
void decrypt(char *buff)
{
	int i,j,k,m;
	WORD a[8],b[8],*x,*y,*t;
	for (i=j=0;i<Nb;i++,j+=4)
	{
		a[i]=pack((BYTE *)&buff[j]);
		a[i]^=rkey[i];
	}
	k=Nb;
	x=a;
	y=b;
	for (i=1;i<Nr;i++)
	{
		for (m=j=0;j<Nb;j++,m+=3)
		{
			y[j]=rkey[k++]^rtable[(BYTE)x[j]]^
				ROTL8(rtable[(BYTE)(x[ri[m]]>>8)])^
				ROTL16(rtable[(BYTE)(x[ri[m+1]]>>16)])^
				ROTL24(rtable[x[ri[m+2]]>>24]);
		}
		t=x; x=y; y=t;
	}
	for (m=j=0;j<Nb;j++,m+=3)
	{
		y[j]=rkey[k++]^(WORD)rbsub[(BYTE)x[j]]^
			ROTL8((WORD)rbsub[(BYTE)(x[ri[m]]>>8)])^
			ROTL16((WORD)rbsub[(BYTE)(x[ri[m+1]]>>16)])^
			ROTL24((WORD)rbsub[x[ri[m+2]]>>24]);
	}
	for (i=j=0;i<Nb;i++,j+=4)
	{
		unpack(y[i],(BYTE *)&buff[j]);
		x[i]=y[i]=0;
	}
	return;
}

int main()
{
	//nb表示分组长度；nk表示密钥长度
	int i,nb,nk;
	char str[]="abcd1234567890123456789012345678901212345678901234567890123456789012";
    char key[32];
	char block[32];
	gentables();
	strtoHex(str,key);
	hextoStr(key,str);
	printf("Key=");
	for (i=0;i<64;i++)
		printf("%c",str[i]);
	printf("\n");
	for (i=0;i<32;i++)
		block[i]=i;
	for (nb=4;nb<=8;nb+=2)
		for (nk=4;nk<=8;nk+=2)
		{
			printf("\nBlock Size= %d bits, Key Size= %d bits\n",nb*32,nk*32);
			gkey(nb,nk,key);
			printf("Plain= ");
			for (i=0;i<nb*4;i++)
				printf("%02x",block[i]);
			printf("\n");
			//进行加密
			encrypt(block);
			//输出密文
			printf("Encrypt= ");
			for (i=0;i<nb*4;i++)
				printf("%02x",(unsigned char)block[i]);
			printf("\n");
			//进行解密
			decrypt(block);
			//输出明文
			printf("Decrypt= ");
			for (i=0;i<nb*4;i++)
				printf("%02x",block[i]);
			printf("\n");
		}
		system("pause");
		return 0;
}
