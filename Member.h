
#include <iostream>
#include<vector>


using namespace std;

static int counter=0;
static int numID=0;

class Member{

private:   
    string name;
    string password = " ";
    string gender = " ";
    int age = 0;
    int id;
    int numOfFollowers;
    int numOfFollowing;
    vector<Member*>Following; //i follow after him
    vector<Member*>Followers; //he follows after me
 
public:
 //Default constructor.
     Member(); 
   //Destructor
     ~Member();

    Member(string name, string password, string gender, int age);
    
    void setName(string name);
    
    string getName();

    void setPassword(string password);

    string getPassword();

    void setGender(string gender);

    string getGender();

    void setAge(int age);

    int getAge();
    
    int numFollowers(); 
 
    void follow(Member& u);

    void unfollow(Member& u);
    
    void unFollowers(Member& u);
    
    void newFollowers(Member& u);
    
    int numFollowes();
    
    int numFollowing();

    static int count();
};
