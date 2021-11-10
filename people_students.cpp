#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void swap(int &xp, int &yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}
class People
{
	protected:
	    string name, brithday;
      public:
          People()
    	    {
          	  name="x..x..x";
          	  brithday="dd/mm/yy";
          }
          
          ~People()
    	    {
     	        name="";
		  brithday="";	   
          }
          void set()
   	    {
          	  cout<<"Nhap Ho va Ten:";
	        getline(cin,name);
          	  cout<<"Nhap ngay thang nam sinh:";
              getline(cin,brithday);
          }
          void get()
   	    {
          	  cout<<name<<"   "<<brithday<<"   ";
          }
};
class Students : public People
{
	private:
	    string sbd;
	    float math, physical , chemistry;
      public:
          Students()
          {    
     	         sbd="0xxx";
     	         math=physical=chemistry=0;
          }
          ~Students()
          {
          	   sbd="";
          	   math=physical=chemistry=0;
          }
          void set()
          {    
               People::set();
          	   cout<<"Nhap so bao danh:";
          	   getline(cin,sbd);
          	   cout<<"Nhap diem toan:";
          	   cin>>math;
          	   cout<<"Nhap diem ly:";
          	   cin>>physical;
          	   cout<<"Nhap diem hoa:";
          	   cin>>chemistry;
          	   cin.ignore();
          }
          void get()
    	    {    
    	         People::get();
          	   cout<<sbd<<"   "<<math<<" "<<physical<<" "<<chemistry<<endl;
          }
          friend bool operator >(Students a, Students b)
    	    {
          	   return (a.math+a.physical+a.chemistry)>(b.math+b.physical+b.chemistry);
          }
          string getID(){
          	   return sbd;
          }
          bool operator >=(int x)
          {
          	  return (this->math >=x && this->physical >=x && this->chemistry>=x);
          }
};
int main(){
	int n;
	cout<<"Nhap vao so luong thi sinh:";cin>>n;
	cin.ignore();
	Students *arr = new Students[n];
	for(int i=0;i<n;i++){
		cout<<"__Nhap thong tin cho thi sinh thu "<<i+1<<":"<<endl;
		arr[i].set();
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(arr[i]>arr[j]) swap(arr[i],arr[j]);
		}
	}
	cout<<"-----Danh Sach Thi Sinh Co Tong Diem Ba Mon Tang Dan-----"<<endl;
	for(int i=0;i<n;i++){
		arr[i].get();
	}
	cout<<endl;
	string ID;
	cout<<"Nhap vao so bao danh:";
	getline(cin,ID);
	cout<<"-----Thong Tin Thi Sinh Can Tim La-----"<<endl;
	int m=-1;
	for(int i=0;i<n;i++){
		if(arr[i].getID()==ID) m=i;
	}
	if(m!=-1) arr[m].get();
	else cout<<"Thi Sinh Can Tim Khong Co Trong Danh Sach"<<endl;
	int count=0;
	for(int i=0;i<n;i++){
		if(arr[i]>=5){
			arr[i].People::get();
			count++;
		};
	}
	cout<<endl;
	cout<<"Phan tram thi sinh co diem ca ba mon lon hon 5 la:";
	cout<<fixed<<setprecision(2)<<((float(count)/n))*100<<"%"<<endl;
	return 0;
}