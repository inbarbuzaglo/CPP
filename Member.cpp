#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include<fstream>
#include<vector>
#include <queue>
#include<iomanip>


using namespace std;

// Includes header files for clarity.
#include "Member.h"


/**************************************************************************************************/

//The Users class has two vectors of type Users* and a string variable which are used by the Graph class to create the directed Graph.

//count how many activate members there are

int Member::counter=0;

int Member::count()
{
    return counter;
}

//Default constructor.
Member::Member()
{
    name = " ";
    password = " ";
    gender = " ";
    age = 0;
    counter++;
}

//Parameterized constructor which initializes the string.
Member::Member(string name, string password, string gender, int age)
{
    this->name = name;
    this->password = password;
    this->gender = gender;
    this->age = age;
    counter++;
    
}

//Setter method which sets the name of the user.
void Member::setName(string name)
{
    this->name = name;
}

//Getter method which gets the password of the user.
string Member::getName()
{
    return this->name;
}
//Setter method which sets the password of the user.
void Member::setPassword(string password)
{
    this->password = password;
}

//Getter method which gets the password of the user.
string Member::getPassword()
{
    return this->password;
}
//Setter method which sets the Gender of the user.
void Member::setGender(string gender)
{
    this->gender = gender;
}

//Getter method which gets the Gender of the user.
string Member::getGender()
{
    return this->gender;
}
//Setter method which sets the age of the user.
void Member::setAge(int age)
{
    this->age = age;
}

//Getter method which gets the age of the user.
int Member::getAge()
{
    return this->age;
}
//Getter method which gets the followers from the follower vector.
int Member::numFollowers()
{
    return Followers.size() ;
}
//Setter method which adds the following to the following vector.îé ùàðé òå÷á àçøéå
void Member::follow(Member &u)
{
       if(find(Followers.begin(),Followers.end(), u.name) ==Followers.end() )
       {
       Followers.push_back(u.name);
        u.Following.push_back(name);
     }
}
void Member::unfollow(Member &u)
{
    for(int i = 0; i<Following.size(); i++)
    {
        if(Following[i] == &u)
        {
            Following.erase(Following.begin() +i );
            break;
        }
    }
          for(int i = 0; i<Followers.size(); i++)
          {
        if(Followers[i] == &u)
        {
            Followers.erase(Followers.begin() +i );
            break;
        }
    }
    

}
//Getter method which gets the following from the following vector.
int Member::numFollowing()
{
    return Following.size();
}
//destructor member 
Member::~Member()
{
    counter--;
}
