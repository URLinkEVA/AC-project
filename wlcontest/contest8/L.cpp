#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
using db=long double;
const db eps=1e-6;
ll abs(ll x){return x>=0?x:-x;}
struct point
{
	ll x,y;
	point operator+(const point &p)const{return {x+p.x,y+p.y};}
	point operator-(const point &p)const{return {x-p.x,y-p.y};}
	point operator*(ll k)const{return {x*k,y*k};}
	point operator/(ll k)const{return {x/k,y/k};}
	ll operator*(const point &p)const{return x*p.y-y*p.x;}
	ll operator^(const point &p)const{return x*p.x+y*p.y;}
	bool operator==(const point &p)const{return x==p.x and y==p.y;}
	bool operator!=(const point &p)const{return x!=p.x or y!=p.y;}
	bool operator<(const point &p)const{if(x!=p.x)return x<p.x;return y<p.y;}
	friend istream& operator>>(istream &is,point &p){int x,y;is>>x>>y;p.x=x;p.y=y;return is;}
	friend ostream& operator<<(ostream &os,const point &p){long long x=p.x,y=p.y;os<<x<<' '<<y;return os;}
	ll abs2()const{return x*x+y*y;}
	db abs()const{return hypot((db)x,(db)y);}
	db dis(const point &p)const{return (*this-p).abs();}
	point shrink()const{ll d=__gcd(::abs(x),::abs(y));if(y>0 or (y==0 and x>0))return {x/d,y/d};else return {-x/d,-y/d};}
	point turn(const point &p)const{return {x*p.x-y*p.y,x*p.y+y*p.x};}
};
struct line
{
	point P,Q;
	friend istream& operator>>(istream &is,line &l){is>>l.P>>l.Q;return is;}
	point dir()const{return (Q-P).shrink();}
	void shrink(){Q=P+dir();}
	bool include(const point &p)const{return (Q-P)*(p-P)>0;}
	bool operator==(const line &l)const{if(Q-P!=l.Q-l.P)return false;return (Q-P)*(l.P-P)==0;}
	bool operator<(const line &l)const{auto dd=Q-P,ddl=l.Q-l.P;if(dd!=ddl)return dd<ddl;return l.include(P);}
};
//point proj(const line &L,const point &q){point k=L.Q-L.P;return L.P+k*((q-L.P)^k/k.abs2());}
//point reflect(const line &L,const point &q){return proj(L,q)*2-q;}
point getLL(const line &L1,const line &L2)
{
	ll w1=(L1.P-L2.P)*(L2.Q-L2.P),w2=(L2.Q-L2.P)*(L1.Q-L2.P);
	return (L1.P*w2+L1.Q*w1)/(w1+w2);
}
pair<db,db> getLLdb(const line &L1,const line &L2)
{
	ll w1=(L1.P-L2.P)*(L2.Q-L2.P),w2=(L2.Q-L2.P)*(L1.Q-L2.P);
	point tmp=(L1.P*w2+L1.Q*w1);
	return {1.0*tmp.x/(w1+w2),1.0*tmp.y/(w1+w2)};
}
pair<ll,ll> getLLfrac(const line &L1,const line &L2)// must be on x-axis
{
	ll w1=(L1.P-L2.P)*(L2.Q-L2.P),w2=(L2.Q-L2.P)*(L1.Q-L2.P);
	point tmp=(L1.P*w2+L1.Q*w1);
	ll fp=tmp.x,fq=w1+w2;
	ll d=__gcd(abs(fp),abs(fq));
	if(fq<0)d=-d;
	return {fp/d,fq/d};
}
db getR(pair<db,db> A,point B)
{
	return hypot(A.first-B.x,A.second-B.y);
}
int main()
{
	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	int T;
	cin>>T;
	int acnt=0;
	for(int tt=1;tt<=T;tt++)
	{
		int n,q;
		cin>>n>>q;
		vector<line> L(n);
		for(int i=0;i<n;i++)
		{
			cin>>L[i];
			L[i].shrink();
		}
		sort(L.begin(),L.end());
		L.resize(unique(L.begin(),L.end())-L.begin());
		n=L.size();
		point dir1=L[0].dir(),sft=L[0].P,sft2={0,0};
		db coeff=dir1.abs();
//		cerr<<"dir1 "<<dir1<<endl;
		dir1.y*=-1;
		int circ=0,inter=1,d90=0,d45=0;
		for(int i=0;i<n;i++)
		{
			L[i].P=(L[i].P-sft).turn(dir1);
			L[i].Q=(L[i].Q-sft).turn(dir1);
			L[i].shrink();
			point diri=L[i].Q-L[i].P;
			if(diri==(point){1,0}){if(i!=0)inter=0;}
			else if(diri==(point){0,1})d90=1;
			else if(diri==(point){1,1} or diri==(point){-1,1})d45=1;
			else circ=1;
		}
//		for(int i=0;i<n;i++)
//			cerr<<"Line "<<i<<" after turning: "<<L[i].P<<' '<<L[i].Q<<endl;
		pair<db,db> center={0,0};
		pair<ll,ll> xpos={0,0};
		if(inter and n>=2)
		{
			center=getLLdb(L[0],L[1]);
			xpos=getLLfrac(L[0],L[1]);
			for(int i=2;i<n;i++)
			{
				if(L[i].dir()!=L[0].dir())
				{
					pair<ll,ll> tmp=getLLfrac(L[i],L[0]);
					if(xpos!=tmp)
					{
						inter=0;
						break;
					}
				}
			}
		}
		function<db(point,point)> getdis;
		//case 1: all parallel
		if(circ==0 and d90==0 and d45==0)
		{
//			cerr<<"case 1"<<endl;
			//case 1.1: one line
			if(n==1)
			{
				getdis=[&](point A,point B)
				{
					if(A.y<0)A.y*=-1;
					if(B.y<0)B.y*=-1;
					return A.dis(B);
//					return min(A.dis(B),A.dis({B.x,-B.y}));
				};
			}
			//case 1.2: parallel lines
			else
			{
				ll d=0;
				for(const auto &l:L)
				{
					d=__gcd(d,abs(l.P.y));
				}
				d*=2;
//				cerr<<hL.P<<' '<<hL.Q<<endl;
//				cerr<<hL2.P<<' '<<hL2.Q<<endl;
				getdis=[&,d](point A,point B)
				{
					A.y%=d;if(A.y<0)A.y+=d;
					B.y%=d;if(B.y<0)B.y+=d;
					if(A.y>d/2)A.y=d-A.y;
					if(B.y>d/2)B.y=d-B.y;
					return A.dis(B);
//					point C={B.x,d-B.y};
//					return min(A.dis(B),A.dis(C));
				};
			}
		}
		//case 2: 90 degrees
		else if(circ==0 and d45==0)
		{
//			cerr<<"case 2"<<endl;
			vector<line> H,V;
			for(const auto &l:L)
			{
				if(l.dir()==(point){1,0})H.push_back(l);
				else V.push_back(l);
			}
			sft2={V[0].P.x,0};
			for(auto &l:L){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			for(auto &l:H){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			for(auto &l:V){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			//case 2.1: two lines
			if((int)V.size()==1 and (int)H.size()==1)
			{
				getdis=[&](point A,point B)
				{
					if(A.x<0)A.x*=-1;
					if(B.x<0)B.x*=-1;
					if(A.y<0)A.y*=-1;
					if(B.y<0)B.y*=-1;
					return A.dis(B);
//					return min(A.dis(B),A.dis({B.x,-B.y}));
				};
			}
			//case 2.2: horizontal parallel
			else if((int)V.size()==1)
			{
				ll dH=0;
				for(const auto &l:H)
				{
					dH=__gcd(dH,abs(l.P.y));
				}
				dH*=2;
				getdis=[&,dH](point A,point B)
				{
					if(A.x<0)A.x*=-1;
					if(B.x<0)B.x*=-1;
					A.y%=dH;if(A.y<0)A.y+=dH;
					B.y%=dH;if(B.y<0)B.y+=dH;
					if(A.y>dH/2)A.y=dH-A.y;
					if(B.y>dH/2)B.y=dH-B.y;
					return A.dis(B);
				};
			}
			//case 2.3: vertical parallel
			else if((int)H.size()==1)
			{
				ll dV=0;
				for(const auto &l:V)
				{
					dV=__gcd(dV,abs(l.P.x));
				}
				dV*=2;
				getdis=[&,dV](point A,point B)
				{
					A.x%=dV;if(A.x<0)A.x+=dV;
					B.x%=dV;if(B.x<0)B.x+=dV;
					if(A.x>dV/2)A.x=dV-A.x;
					if(B.x>dV/2)B.x=dV-B.x;
					if(A.y<0)A.y*=-1;
					if(B.y<0)B.y*=-1;
					return A.dis(B);
				};
			}
			//case 2.4: both parallel
			else
			{
				ll dH=0;
				for(const auto &l:H)
				{
					dH=__gcd(dH,abs(l.P.y));
				}
				dH*=2;
				ll dV=0;
				for(const auto &l:V)
				{
					dV=__gcd(dV,abs(l.P.x));
				}
				dV*=2;
				getdis=[&,dH,dV](point A,point B)
				{
					A.x%=dV;if(A.x<0)A.x+=dV;
					B.x%=dV;if(B.x<0)B.x+=dV;
					if(A.x>dV/2)A.x=dV-A.x;
					if(B.x>dV/2)B.x=dV-B.x;
					A.y%=dH;if(A.y<0)A.y+=dH;
					B.y%=dH;if(B.y<0)B.y+=dH;
					if(A.y>dH/2)A.y=dH-A.y;
					if(B.y>dH/2)B.y=dH-B.y;
					return A.dis(B);
				};
			}
		}
		//case 3: 45 degrees
		else if(circ==0)
		{
//			cerr<<"case 3"<<endl;
			vector<line> H,V,D;
			for(const auto &l:L)
			{
				if(l.dir()==(point){1,0})H.push_back(l);
				else if(l.dir()==(point){0,1})V.push_back(l);
				else D.push_back(l);
			}
			sft2=getLL(D[0],H[0]);
			for(auto &l:L){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			for(auto &l:H){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			for(auto &l:V){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			for(auto &l:D){l.P=l.P-sft2;l.Q=l.Q-sft2;}
			//case 3.1: intersect at one point
			if(inter)
			{
				getdis=[&](point A,point B)
				{
					if(A.x<0)A.x*=-1;
					if(B.x<0)B.x*=-1;
					if(A.y<0)A.y*=-1;
					if(B.y<0)B.y*=-1;
					if(A.y>A.x)swap(A.x,A.y);
					if(B.y>B.x)swap(B.x,B.y);
					return A.dis(B);
//					return min(A.dis(B),A.dis({B.x,-B.y}));
				};
			}
			//case 3.2: does not intersect at one point
			else
			{
				ll dH=0;
				for(const auto &l:H)
				{
					dH=__gcd(dH,abs(l.P.y));
				}
				dH*=2;
				ll dV=0;
				for(const auto &l:V)
				{
					dV=__gcd(dV,abs(l.P.x));
				}
				dV*=2;
				ll dD=0;
				for(const auto &l:D)
				{
//					point tmp=getLL(l,H[0]);
//					if(tt==1491)cerr<<"intersection "<<tmp<<endl;
					dD=__gcd(dD,abs(getLL(l,H[0]).x));
				}
				dD*=2;
				//case 3.2.1: hypotenuse on x-axis
				ll fd=__gcd(dD,dH);
				fd=__gcd(fd,dV);
				if(dD!=0 and (dD/fd)%2==1)
				{
					dD=fd;
					getdis=[&,dD](point A,point B)
					{
//						cerr<<"case 3.2.1 "<<(long long)dD<<endl;
						A.x%=dD;if(A.x<0)A.x+=dD;
						B.x%=dD;if(B.x<0)B.x+=dD;
						if(A.x>dD/2)A.x=dD-A.x;
						if(B.x>dD/2)B.x=dD-B.x;
						A.y%=dD;if(A.y<0)A.y+=dD;
						B.y%=dD;if(B.y<0)B.y+=dD;
						if(A.y>dD/2)A.y=dD-A.y;
						if(B.y>dD/2)B.y=dD-B.y;
						if(A.y>A.x)swap(A.x,A.y);
						if(B.y>B.x)swap(B.x,B.y);
						if(A.x+A.y>dD/2)A={dD/2-A.y,dD/2-A.x};
						if(B.x+B.y>dD/2)B={dD/2-B.y,dD/2-B.x};
						return A.dis(B);
					};
				}
				//case 3.2.2: leg on x-axis
				else
				{
					dD=fd;
					getdis=[&,dD](point A,point B)
					{
//						cerr<<"case 3.2.2"<<endl;
						A.x%=dD;if(A.x<0)A.x+=dD;
						B.x%=dD;if(B.x<0)B.x+=dD;
						if(A.x>dD/2)A.x=dD-A.x;
						if(B.x>dD/2)B.x=dD-B.x;
						A.y%=dD;if(A.y<0)A.y+=dD;
						B.y%=dD;if(B.y<0)B.y+=dD;
						if(A.y>dD/2)A.y=dD-A.y;
						if(B.y>dD/2)B.y=dD-B.y;
						if(A.y>A.x)swap(A.x,A.y);
						if(B.y>B.x)swap(B.x,B.y);
						return A.dis(B);
					};
				}
			}
		}
		//case 4: messy
		else
		{
//			cerr<<"case 4"<<endl;
			//case 4.1: intersect at one point - circle
			if(inter)
			{
				getdis=[&](point A,point B)
				{
					return fabs(getR(center,A)-getR(center,B));
				};
			}
			//case 4.2: fill the plane
			else
			{
				getdis=[&](point A,point B)
				{
					return 0.0;
				};
			}
		}
		for(int qq=1;qq<=q;qq++)
		{
			point A,B;
			cin>>A>>B;
			A=(A-sft).turn(dir1)-sft2;
			B=(B-sft).turn(dir1)-sft2;
//			cerr<<A<<' '<<B<<endl;
			++acnt;
			/*
			if(acnt==89328)
			{
				cerr<<"test case "<<tt<<", query "<<qq<<' '<<", n = "<<n<<", lines :"<<endl;
				for(auto l:L)cerr<<l.P<<' '<<l.Q<<endl;
				cerr<<"points: "<<A<<' '<<B<<endl;
			}
			*/
			cout<<fixed<<setprecision(12)<<getdis(A,B)/coeff<<"\n";
//			if(acnt==89328)return 0;
		}
	}
	return 0;
}

