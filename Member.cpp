
#include <iostream>
#include <algorithm>
#include "Member.h"


using namespace std;

//Default constructor.
Member::Member()
{
    counter++;
    name = " ";
    password = " ";
    gender = " ";
    age = 0;
    id=++userID;
  
}
//destructor member 
Member::~Member()
{
   count--;
}

//Parameterized constructor which initializes the string.
Member::Member(string name, string password, string gender,int age)
{
    this->name = name;
    this->password = password;
    this->gender = gender;
    this->age = age;
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

//Setter method which adds the following to the following vector.îé ùàðé òå÷á àçøéå
void Member::follow(Member& u)
{
       if(find(Following.begin(),Following.end(), u.userID) ==Following.end() )
       {
       Following.push_back(u.userID);
        u.Followers.push_back(userID);
     }
}
void Member::unfollow(Member& u)
{
    for(int i = 0; i<Following.size(); i++)
    {
        if(Following[i] == u.userID)
        {
            Following.erase(Following.begin() +i );
            
        }
    }
          for(int i = 0; i<u.Followers.size(); i++)
          {
        if(u.Followers[i] == userID)
        {
            u.Followers.erase(u.Followers.begin() +i );
            
        }
    }

}
//Getter method which gets the following from the following vector.
int Member::numFollowers()
{
    return Followers.size();
}
int Member::numFollowing()
{
    return Following.size();
}

void Member::newFollowers(Member &m)
{
    numFollowers++;
    Followers.push_back(&m);
}
int Member::count()
{
    return return counter;
}
