#include <iostream>
#include <string>
#include <vector>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
class CongNhan
{
	protected:
	    string hoten;
      public:
          void virtual nhap()
          {
          	 cout<<"Nhap ho ten:";
          	 getline(cin,hoten);
          }
          void virtual in()
          {
          	 cout<<hoten<<"  ";
          }
          double virtual tinhluong()=0;
          int virtual getsp(){
          	 return 0;
          };
};
class NQl: public CongNhan
{
	private:
	    long luongX;
      public:
          void nhap()
          {
          	  CongNhan::nhap();
          	  cout<<"Nhap khoan luong cd phai tra:";
          	  cin>>luongX;
    	  	  cin.ignore();
          }
          void in()
          {
          	  CongNhan::in();
          	  cout<<luongX<<"  ";
          }
          double tinhluong()
    	    {
          	  return luongX;
          }
          
};
class CNTG: public CongNhan
{
	private:
	    long giolam; 
	    long luongY;
      public:
          void nhap()
          {
       	  CongNhan::nhap();
          	  cout<<"Nhap gio lam cua cong nhan:";
          	  cin>>giolam;
          	  cout<<"Nhap khoan luong cd phai tra:";
          	  cin>>luongY;
    	  	  cin.ignore();
          }
          void in()
          {
          	  CongNhan::in();
          	  cout<<giolam<<"  "<<luongY<<"  ";
          }
          double tinhluong()
    	    {
          	  if(giolam < 40) return luongY;
          	  else return luongY + (float(giolam-40)/40)*luongY*3/2;
          }
          
};
class CNLN: public CongNhan
{
	private:
	    long doanhsoZ;
      public:
          void nhap()
	    {
    		  CongNhan::nhap();
          	  cout<<"Nhap gia tri doanh so z:";
          	  cin>>doanhsoZ;
          	  cin.ignore();
    	    }
	    void in()
	    {
    		  CongNhan::in();
          	  cout<<doanhsoZ<<"  ";
    	    }
	    double tinhluong() 
	    {
    		  return 500000 + (float(7)/100)*doanhsoZ;
     	    }
};
class CNSP: public CongNhan
{
	private:
	    long sosp;
	    long tien1sp; 
      public:
          void nhap()
	    {
    		  CongNhan::nhap();
          	  cout<<"Nhap so san phan cua cong nhan:";
          	  cin>>sosp;
	        cout<<"Nhap gia tien cua mot san pham:";
          	  cin>>tien1sp;
    	    }
	    void in()
	    {
    		  CongNhan::in();
          	  cout<<sosp<<"  "<<tien1sp<<"  ";
    	    }
	    double tinhluong() 
	    {
    		  return sosp*tien1sp;
     	    }
     	    int getsp(){
    	     	     return sosp;
          }
};
class CongTy
{
	private:
	    vector<CongNhan *> ds_CongNhan;
	    vector<CongNhan *> ds_CongNhanSP;
	public:
	    void Input();
	    void Output();
	    void sortNVSP(); 
	    void Output1();
};
void CongTy::Input()
{
	int maso;
	while(true){
		cout<<"============== Cong Nhan =============="<<endl;
		cout<<"1. Nha Quan Ly"<<endl;
		cout<<"2. Cong Nhan Lam Theo Gio"<<endl;
		cout<<"3. Cong Nhan Lam Theo Loi Nhuan"<<endl;
		cout<<"4. Cong Nhan Lam Theo San Pham"<<endl;
		cout<<"0. Thoat"<<endl;
		cout<<"==============    END    =============="<<endl;
		cout<<"Nhap ma so cong nhan:";
		cin>>maso;
		cin.ignore();
		CongNhan *x;
		if(maso == 1){
			x = new NQl;
			cout<<"Nhap Thong Tin Cho Nhan Quan Ly:"<<endl;
			x->nhap();
			ds_CongNhan.push_back(x);	
		}
		else if(maso == 2){
			x = new CNTG;
			cout<<"Nhap Thong Tin Cho Cong Nhan Lam Theo Thoi Gian:"<<endl;
			x->nhap();
			ds_CongNhan.push_back(x);	
		}
		else if(maso == 3){
			x = new CNLN;
			cout<<"Nhap Thong Tin Cho Cong Nhan Lam Theo Loi Nhuan:"<<endl;
			x->nhap();
			ds_CongNhan.push_back(x);	
		}
		else if(maso == 4){
			x = new CNSP;
			cout<<"Nhap Thong Tin Cho Cong Nhan Lam Theo San Pham:"<<endl;
			x->nhap();
			ds_CongNhan.push_back(x);
			ds_CongNhanSP.push_back(x);	
		}
		else if(maso == 0){
		      break;	
		}
	}
}
void CongTy::Output()
{
	cout<<"======DANH SACH THONG TIN CAC LOAI CONG NHAN======="<<endl;
	for(int i=0;i<ds_CongNhan.size();i++){
			cout<<"Thong Tin Cong Nhan Thu "<<i+1<<endl;
		      ds_CongNhan[i]->in();
		      cout<<ds_CongNhan[i]->tinhluong()<<endl;
	}
}
void CongTy::sortNVSP()
{
	for(int i=0;i<ds_CongNhanSP.size()-1;i++){
		for(int j=i+1;j<ds_CongNhanSP.size();j++){
			if(ds_CongNhanSP[i]->getsp() > ds_CongNhanSP[j]->getsp()){
				swap(ds_CongNhanSP[i],ds_CongNhanSP[j]);
			}
		}
	
	}
}
void CongTy::Output1()
{
	cout<<"======DANH SACH CONG NHAN LAM THEO SAN PHAM DA DUOC SAP XEP======="<<endl;
	for(int i=0;i<ds_CongNhanSP.size();i++){
		      ds_CongNhanSP[i]->in();
		      cout<<ds_CongNhanSP[i]->tinhluong()<<endl;
	}
}
int main()
{
	CongTy *x = new CongTy;
	x->Input();
	x->Output();
	x->sortNVSP();
	x->Output1();
	return 0;
}

