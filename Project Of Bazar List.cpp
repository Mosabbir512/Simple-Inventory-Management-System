#include<bits/stdc++.h>
using namespace std;
string x;
void addItem()
{
    cout<<endl<<endl;
    ofstream write;
    write.open("add.txt",ios::app);
    int n;
    cout<<"     Enter the number of Items :";
    cin>>n;
    cout<<endl<<"     Enter "<<n<<" element"<<endl<<endl;

    while(n--)
    {
        cout<<"           ";
        cin>>x;
        write<<x<<"\n";
    }
    write.close();

}
void showItem()
{
    int p=0;
    ifstream read;
    read.open("add.txt",ios::in);
    while(!read.eof())
    {
        read>>x;
        p++;
    }
    read.close();
    p--;
    cout<<"\n\n     Total item = "<<p<<"\n\n";

    ifstream read1;
    read1.open("add.txt",ios::in);
    while(!read1.eof()&&p>0)
    {
        read1>>x;
        p--;
        cout<<"       "<<x<<endl;

    }
    read1.close();

}
void showselectitem()
{
    int p=0;
    ifstream read;
    read.open("add1.txt",ios::in);
    while(!read.eof())
    {
        read>>x;
        p++;

    }
    read.close();
    p--;
    cout<<endl<<endl<<endl;
    cout<<"\n\n             Total item selected  = "<<p<<"\n\n";
    ifstream read1;
    int l=0;
    read1.open("add1.txt",ios::in);
    while(!read1.eof()&&p>0)
    {
        l++;
        read1>>x;
        p--;
        cout<<"              "<<l<<". "<<x<<endl;
    }
    read1.close();

}
void searching()
{
    int n,k=0;
    vector<string>v;
    while(true)
    {
        cout<<endl<<endl;
        cout<<"\n      (1) For Search \n";
        cout<<"      (2) For Finish  \n";
        cout<<endl<<"      select one : ";
        cin>>n;
        if(n==1)
        {
            ifstream read;
            read.open("add.txt",ios::in);
            char p;
            vector<string>d;
            cout<<endl<<"      Which letter you Search :  ";cin>>p;
            string z;
            bool f=false;
            while(!read.eof())
            {
                read>>x;

                if(x[0]==p)
                {
                    d.push_back(x);
                    f=true;
                }
            }
            read.close();
            cout<<endl<<endl<<endl<<endl<<endl<<"      Your Searching List is : "<<endl<<endl;
            if(f==true)
            {
                for(int i=0; i<d.size(); i++)
                {
                    cout<<"           "<<i+1<<"."<<d[i]<<endl;

                }
                 int s;
                cout<<endl<<"       Enter the number to select Item : ";cin>>s;
                bool ff=false;
                for(int i=0; i<d.size(); i++)
                {
                    if(s-1==i)
                    {
                        ff=true;
                        v.push_back(d[i]);
                        break;
                    }

                }
                cout<<" \n       Succefully  selected"<<endl;
                if(ff==false)
                {
                    cout<<"\n       You enter wrong item\n";
                }

            }
            else
                cout<<"        NOt found\n";

        }
        else
        {
            //cout<<"List are:"<<endl;
            ofstream write;
            write.open("add1.txt",ios::app);
            for(int i=0; i<v.size(); i++)
            {
                 write<<v[i]<<endl;
               // cout<<v[i]<<endl;
            }
            write.close();

           // showselectitem();
            break;
        }


    }
}
int main()
{
    int n;
    while(true)
    {

        cout<<endl<<endl<<endl;
        cout<<"           -----------------------------"<<endl;
        cout<<"           -----------------------------"<<endl;
        cout<<"               Choose your option \n\n";
        cout<<"                1. For add item \n";
        cout<<"                2. For show all item  \n";
        cout<<"                3. For searcing item\n";
        cout<<"                4. For show select\n";
        cout<<"                5. For exit \n";
        cout<<"           -----------------------------"<<endl;
        cout<<"           -----------------------------"<<endl;
        cout<<endl<<endl<<endl<<"             Enter your option : ";
        cin>>n;
        switch(n)
        {
        case 1:
            addItem();
            break;
        case 2:
            showItem();
            break;
        case 3:
            searching();
            break;
        case 4:
            showselectitem();
            break;

        }
        if(n==5)
            break;

    }
}

