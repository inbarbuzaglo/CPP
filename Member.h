
#include <iostream>
#include<vector>


using namespace std;

static int counter=0;
static int numID=0;

//The Users class has two vectors of type Users* and a string variable which are used by the Graph class to create the directed Graph.
class Member{

private:   
    string name;
    string password = " ";
    string gender = " ";
    int age = 0;
    int id;
    int numOfFollowers;
    int numOfFollowing;
    vector<Member*>Following; //follow
    vector<Member*>Followers; //òå÷áéí àçøé
 
public:
 //Default constructor.
     Member(); 
   //Destructor
     ~Member();

    //Parameterized constructor which initializes the string.
    Member(string name, string password, string gender, int age);
    
    //Setter method which sets the name of the user.
    void setName(string name);
    
    //Getter method which gets the name of the user.
    string getName();

    //Setter method which sets the password of the user.
    void setPassword(string password);

    //Getter method which gets the password of the user.
    string getPassword();

    //Setter method which sets the Gender of the user.
    void setGender(string gender);

    //Getter method which gets the Gender of the user.
    string getGender();

    //Setter method which sets the age of the user.
    void setAge(int age);

    //Getter method which gets the age of the user.
    int getAge();
    
    //Getter method which gets the number of Followers
    int numFollowers(); 
 
    //Setter method which adds the following to the following vector.
    void follow(Member& u);

    void unfollow(Member& u);
    
    void unFollowers(Member& u);
    
    void newFollowers(Member &m);
    
    int numFollowes();
     //Getter method which gets the number of Following
    int numFollowing();

    static int count();
};
