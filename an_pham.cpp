#include <iostream>
using namespace std;
class anpham
{
	protected:
	    string name;
	    int giathanh;
      public:
          void set(){
          	 cout<<"Nhap ten:";
          	 getline(cin, name);
          	 cout<<"Nhap gia thanh:";
          	 cin>>giathanh;
          }
          void get(){
          	cout<<name<<"  "<<giathanh<<"  ";
          }
};
class sach : public anpham
{
	private:
	    int sotrang;
      public:
          void set(){
          	 anpham::set();
          	 cout<<"Nhap so trang:";cin>>sotrang;
          	 cin.ignore();
          }
          void get(){
          	 anpham::get();
          	 cout<<sotrang<<endl;
          }
          bool operator >(int x){
          	 return sotrang > 500;
          }
};
class CD : public anpham
{
	private:
	    int sophut;
      public:
          void set(){
          	 anpham::set();
          	 cout<<"Nhap so phut:";cin>>sophut;
          	 cin.ignore();
          }
          void get(){
          	 anpham::get();
          	 cout<<sophut<<endl;
          }
          string getName(){
          	 return name;
          }
};
int main(){
	int n;
	cout<<"Nhap vao so luong trang sach :";cin>>n;
	cin.ignore();
	sach a[n];
	for(int i=0;i<n;i++){
		a[i].set();
	}
	for(int i=0;i<n;i++){
		if(a[i]>500){
			a[i].get();
		};
	}
	string ten;
	cout<<"Nhap ten dia:";
	getline(cin,ten);
	int m;
	cout<<"Nhap vao so luong  dia CD:";cin>>m;
	cin.ignore();
	CD b[m];
	for(int i=0;i<m;i++){
		b[i].set();
	}
	for(int i=0;i<m;i++){
		if(b[i].getName()	== ten){
			b[i].get();
		}
	}
	return 0;
}