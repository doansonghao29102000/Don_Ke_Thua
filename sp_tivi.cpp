#include <iostream>
#include <string>
using namespace std;
void swap(int &xp , int &yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}
class SP
{
	protected:
          string masp;
          string namesp;
          string namsx;
      public:
          SP(string masp="0xx", string namesp="xxx", string namsx="2xxx")
          {
          	  this->masp = masp;
          	  this->namesp = namesp;
          	  this->namsx = namsx;
          }
          ~SP()
          {
          	  masp=namesp=namsx=" ";
          }
          void set()
          {
          	  cout<<"Nhap ma san pham:";
          	  getline(cin,masp);
          	  cout<<"Nhap ten san pham:";
          	  getline(cin,namesp);
          	  cout<<"Nhap nam san xuat:";
          	  getline(cin,namsx);
          }
          void get()
          {
          	  cout<<masp<<"   "<<namesp<<"   "<<namsx<<"    ";
          }
};
class Tivi: public SP
{
	private:
	    int chieu_dai;
	    int chieu_rong;
      public:
          Tivi(int chieu_dai=0, int chieu_rong=0)
          {
  	         this->chieu_dai = chieu_dai;
  	         this->chieu_rong = chieu_rong;
          }
          ~Tivi()
          {
     	         chieu_dai = chieu_rong = 0;
          }
          void set()
    	    {
          	    SP::set();
          	    cout<<"Nhap chieu dai:";
                cin>>chieu_dai;
          	    cout<<"Nhap chieu rong:";
                cin>>chieu_rong;
                cin.ignore();
          }
          void get()
          {
          	    SP::get();
          	    cout<<chieu_dai<<"   "<<chieu_rong<<endl;
          }
          bool operator > (Tivi x)
          {
          	    return (this->chieu_dai*this->chieu_rong > x.chieu_dai*x.chieu_rong);
          }
};
int main(){
	int n;
	cout<<"Nhap vao so luong tivi:";cin>>n;
	cin.ignore();
	Tivi *arr = new Tivi[n];
	for(int i=0;i<n;i++){
		cout<<"__Nhap thong tin cho tivi thu "<<i+1<<":"<<endl;
		arr[i].set();
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}
	cout<<"Danh sach sinh vien sap xep tang dan theo dien tich"<<endl;
	for(int i=0;i<n;i++){
		arr[i].get();
	}
	return 0;
}