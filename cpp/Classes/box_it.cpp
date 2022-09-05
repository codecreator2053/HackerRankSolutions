#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

class Box{
    private:
        int l;
        int b;
        int h;
    public:
        Box(){
            l=0;b=0;h=0;
        };
        Box(int len, int bre, int hei){
            l = len; b = bre; h = hei;
        };
        Box(Box& box){
            l = box.getLength();
            b = box.getBreadth();
            h = box.getHeight();
        }
        int getLength(){
            return l;
        }
        int getBreadth(){
            return b;
        }
        int getHeight(){
            return h;
        }

        //very important to have two "long" here
        long long CalculateVolume(){
            return l* (1ll) * b*h;
        }
        bool operator <(Box& B){
            bool condition1 = l < B.getLength();
            bool condition2 = l==B.getLength() && b < B.getBreadth();
            bool condition3 = l==B.getLength() && b==B.getBreadth() && h < B.getHeight();
            return condition1 || condition2 || condition3;
        }  
        
};


ostream& operator <<(ostream& out, Box& B){
            out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
            return out;
};
        



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}