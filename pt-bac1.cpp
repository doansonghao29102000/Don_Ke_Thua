#include <iostream>
using namespace std;
class HeSo
{
	protected:
	    int a, b;
      public:
          friend istream &operator>>(istream &is, HeSo &x)
	    {
             cout << "Nhap he so a:"; is >> x.a;
             cout<<"Nhap he so b:"; is >> x.b;
             return is;
    	    }
    	    friend ostream &operator<<(ostream &os, HeSo x)
    	    {
	    	   os << "Phuong trinh co dang : P(x) = "<< x.a << "*x + " << x.b << endl;
	    	   return os;
    	    }
};
class PT1: public HeSo
{
	public:
	    friend istream &operator>>(istream &is, PT1 &x)
	    {
             cout << "Nhap he so a:"; is >> x.a;
             cout<<"Nhap he so b:"; is >> x.b;
             return is;
    	    }
    	    friend ostream &operator<<(ostream &os, PT1 x)
    	    {
	    	   os << "Phuong trinh co dang : P(x) = "<< x.a << "*x + " << x.b << endl;
	    	   return os;
    	    }
	    void GiaiPT(){
	    	  if( a == 0 ){
  	    		if( b== 0) cout<<"pt vo so nghiem"<<endl;
  	    		else cout<<"pt vo nghiem"<<endl;
  	    	  }
  	    	  else{
  	    	  	cout<<"nghiem cua phuong trinh la: x = "<<float(a)/b<<endl;
  	    	  }
    	    }
};
int main(){
	PT1 x;
	cin>>x;
	cout<<x;
	x.GiaiPT();
	return 0;
}