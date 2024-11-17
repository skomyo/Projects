#include <iostream>
#include<vector>
using namespace std;

//efficient scheduler
//takes in user input and distributes 
//make vector in main and 

class subject{
    private: 
    string title;
    double start;
    double length;
    
    public:
    subject(string name="sleep", double time=0, double duration=0): title(name), start(time), length(duration){
    }

    string getTitle(){
        return title;
    }
    double getStart(){
        return start;
    }
    double getLength(){
        return length;
    }

    void setTitle( string t){
        title=t;
    }
    void setStart(double s){
        start=s;
    }
    void setLength(double l){
        length =l;
    }

};

class Tasks: public subject{    
    private:
    vector<subject> list;

    public:

    Tasks(){
        int numTasks=0;
        string name="";
        double start=0;
        double duration=0;      

        cout<<"How many tasks do you have?"<<endl;
        cin>>numTasks;
        if(numTasks<=0){
            cout<<"Please enter a valid number of tasks";
            cin>>numTasks;
        }
        cin.ignore();
        

        for(unsigned i=0; i<numTasks;++i){
            cout<<"Name of the task?:"<<endl;
            getline(cin,name);
            cout<<"Time when the task starts (military time and in decimals)?:"<<endl;
            cin>>start;
            while(start>23){
                cout<<"That is not a valid time, please try again"<<endl;
                cin>>start;
            }
            cout<<"What is the maximum number of minutes it would take to finish this task?:"<<endl;
            cin>>duration;
            cin.ignore();
            subject temp(name, start, duration);
            list.push_back(temp);
        }

    }

    void sortList(){
         int early=0;
        for(unsigned i=0; i<list.size()-1;++i){
            early =i;
            for(unsigned j=i+1; j<list.size();++j){
                if(list.at(j).getStart() > list.at(early).getStart()){
                    early=j;
                }
            }
            swap(list.at(i), list.at(early));
        }
    }

    void print(){
        if(list.empty()){
            cout<<"You have nothing in your schedule. Feel free to do anything!\n";
        }
        else{
            for(unsigned i=0; i<list.size(); ++i){
                int hours= list.at(i).getLength() /60;
                    double min=list.at(i).getLength();
                    if(hours>0){
                        min=(list.at(i).getLength() - (hours *60)) /10 ;
                    }
                if(list.at(i).getTitle() == "studying" && list.at(i).getLength() > 60){
                    double starting=list.at(i).getStart();
                    double temp= list.at(i).getStart() + 0.45;
                    int check=0;
                    while(temp< (list.at(i).getStart() + min +hours)){
                        check=0;
                        cout<<starting<<" - "<<temp << ": study"<<endl;
                        cout<<temp<<" - "<<temp+0.25<<" have a small break from studying"<<endl;
                        temp+=0.25; 
                        check=temp;
                        if(check-temp >0.6){
                            temp++;
                            temp-=0.6;
                        }
                        starting=temp;
                        temp=starting +0.45;
                    }
                }
                else{
                    
                    
                    cout<<list.at(i).getStart()<<" - "<<list.at(i).getStart() + min +hours<<" : "<<list.at(i).getTitle()<<endl;
                }
            }
        }
    }

};

int main(){
    Tasks today;
    today.sortList();
    today.print();

    return 0;
}
