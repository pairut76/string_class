//Pairut Dumkuengthanant
//64856070


//#define MAXLEN 128
#include <iostream>
using namespace std;
const int MAXLEN=128;
class String
{
	
public:
	String( const char * s="")
	{
	strcpy(buf, s);
	//cout<<strlen(buf)<<endl;
	//cout<<strchr(buf, 4)<<endl;
	}
	String( const String & s)
	{
	strcpy(buf, s.buf);
	}
	String operator = (const String & s )
	{
	strcpy(this->buf, s.buf);
	return buf;
	}


	char & operator [] ( int index )
	{
	if (inBounds(index-1)){
		return buf[index-1];
		}
	//return NULL;
	}



	int size(){return strlen(buf);}


	String reverse()
	{
	
	int i;
	int buflen=strlen(buf)-1;
	char rev[buflen];
	//cout<<"length: "<<buflen<<endl;
	//cout<<buf<<endl;
	for(i=0; i<=buflen;i++){
		//cout<<i<<"	"<<buf[buflen-i]<<"  "<<buflen-i<<endl;
		rev[i]=buf[buflen-i];
		}
	rev[i]='\0';
	return rev;

	}
	
	int indexOf( const char c)
	{
	for(int i=0; buf[i];i++){
		if(buf[i]==c)
			return i+1;
		}
	} 

	int indexOf( const String pattern )
	{
	int count;
	int ind,i;
	for(int i=0; i<=buf[i];i++)
		{count=0;
		//cout<<"i: "<<i<<" buf: "<<buf[i]<<" pattern: "<<pattern.buf[0]<<endl;
		if(buf[i]==pattern.buf[0])
			{
			//cout<<"found locations: "<<i<<endl;
			ind=i;
			for(int j=1;j<strlen(pattern.buf);j++)
				{
				//cout<<buf[i+j]<<" match: "<<pattern.buf[j]<<endl;
				if(buf[i+j]==pattern.buf[j])
					count+=1;
				}
			if(count==strlen(pattern.buf)-1)
				return i+1;
			
			}
		}
	//cout<<"count: "<<count<<" len pattern: "<<strlen(pattern.buf)<<endl;
	
	}


	bool operator == ( const String s)
	{
	//cout<<"strcmp:" <<strcmp(buf,s.buf)<<endl;
	return (strcmp(buf, s.buf)==0);
	//return false;
	}
		
	
	bool operator != ( const String s)
	{
	return (strcmp(buf, s.buf)!=0);                                    
	}
	bool operator > ( const String s)
	{
	return (strcmp(buf,s.buf)>0);
	}
	bool operator < ( const String s)
	{
	return strcmp(buf, s.buf)<0;
	}
	bool operator <= ( const String s)
	{
	return strcmp(buf,s.buf)<=0;
	}
	bool operator >= ( const String s)
	{
	return strcmp(buf, s.buf)>=0;
	}

	String operator + ( const String s)
	{
	return strcat(buf,s.buf);
	}
	String operator += ( const String s)
	{
	return strcat(buf,s.buf);
	}
	void print( ostream & out)
	{
	out<<buf;
	}
	void read( istream & in)
	{
	in>>buf;
	}
	~String(){}
private:
	
	bool inBounds( int i)
	{
	return i>=0&&i<strlen(buf);
	}

	static int strlen(const char *s)
	{
	int i;
	for(i=0; s[i]!='\0';i++)
		;
	return i;
	}

	static char *strcpy( char *dest, const char *src)
	{
	int i;
	for(i=0; src[i] != '\0' && i < MAXLEN -1 ; i++)
		dest[i]=src[i];
	
	dest[i]='\0';
	}

	static char *strcat( char *dest, const char *src)
	{
	strcpy(dest+strlen(dest), src);
	return dest;
	}

	static int strcmp(const char *left, const char *right)
	{
	int count=-1;
	int lenleft=strlen(left);
	int lenright=strlen(right);
	
	for(int i=0; left[i];++i){
		count++;
		if(right[count]=='\0')
			return 1;
		if(left[i]-right[i]!=0)
			break;
	}
	
	if(lenleft==lenright&&lenright==count+1){
		return 0;
		}
	if(left[count]=='\0');
		return -1;
	return left[count]-right[count];
	}
	static char *strchr(const char *str, int c)
	{
	int i=0;
	while(str[i])
		{
		i++;
		if(*str++==(char) c)
			return (char *)str;
		}
	return NULL;
	}

	char buf[MAXLEN];
};
	ostream & operator << ( ostream & out, String str)
	{
	str.print(out);
	return out;
	}
	istream & operator >> ( istream & in, String & str)
	{
	str.read(in);
	return in;
	}










