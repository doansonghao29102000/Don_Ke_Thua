#include <iostream>
using namespace std;
class mayin
{
	protected:
	    string sohieu;
	    int soluong;
	public:
	    void set()
	    {
            cout<<"Nhap so hieu:";
            getline(cin,sohieu);
            cout<<"Nhap so luong:";
            cin>>soluong;
            cin.ignore();
          } 
     	    void get()
     	    {
    	      cout<<sohieu<<"  "<<soluong<<"  ";	
    	    }
	    
};
class mayinlaser: virtual public mayin
{
	protected:
	    string dpi;
      public:
	    void set()
	    {
    		 cout<<"Nhap dpi:";
    		 cin>>dpi;
    	    }
    	    void get()
    	    {
    	    	 cout<<dpi<<"   ";
    	    }
};
class mayinmau: virtual public mayin
{
	protected:
          string bangmau;
      public:
          void set()
	    {
    		 cout<<"Nhap bang mau:";
    		 cin>>bangmau;
    	    }
    	    void get()
    	    {
    	    	 cout<<bangmau<<"   ";
    	    }
};
class mayinlasermau: public mayinlaser, public mayinmau
{
	public:
	    void set()
	    {
    		 mayin::set();
    		 mayinmau::set();
    		 mayinlaser::set();
     	    }
     	    void get()
     	    {
    	       mayin::get();
		 mayinmau::get();
		 mayinlaser::get();	
          }
};
int main(){
	mayinlasermau x;
	x.set();
	x.get();
	return 0;
}