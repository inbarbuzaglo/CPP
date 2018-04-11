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
    id=++numID;//id of the user
    numOfFollowers=0;//a counter for the amout of followers of mine - who follows after me
    numOfFollowing=0;//a counter for the amout of following -who i follow after
  
}
//destructor member ,loops in order to delete from the vector
Member::~Member()
{
      for(int i=0; i<numOfFollowing; i++){
           unfollow(*Following[i]);//unfollow from my list
        }
    for(int i=0; i<numOfFollowers; i++){
           Followers[i]->unfollow(*this);//unfollow from their list
        }   
   counter--;
}

//Parameterized constructor which initializes .
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

//Getter method which gets the name of the user.
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

//Setter method which adds the following to the following vector. the same for followers 
void Member::follow(Member& u)
{
   if(this->id!=u.id)//if the object isn't in my vector already
   {
    for(int i =0 ; i<numOfFollowing;i++)
    {
     
       if ((Following[i]->id)==(u.id))//if the object is in my vector
       {
        return;
         }
     
    }
    Following.push_back(&u);
     numOfFollowing++;
     u.newFollowers(*this);
   }
}
//to unfollow somone
void Member::unfollow(Member& u)
{
    for(int i = 0; i<numOfFollowing; i++)
    {
        if(Following[i]->id == u.id)//if the object is in my vec
        {
            Following.erase(Following.begin() +i );
            numOfFollowing--;   
            u.unFollowers(*this);
            return;
        }
    }

}
//to take myself of his vec of followers
    void Member::unFollowers(Member& u)
{
    for(int i=0; i<numOfFollowers; i++){
        if(Followers[i]->id == u.id)
        {
            Followers.erase(Followers.begin() + i);
            numOfFollowers--;
            return;
        }
    }  
}
//Getter method which gets the following from the following vector.
int Member::numFollowers()
{
    return numOfFollowers;
}
int Member::numFollowing()
{
    return numOfFollowing;
}
//helper to add myself to someone's vec
void Member::newFollowers(Member& u)
{
    numOfFollowers++;
    Followers.push_back(&u);
}
int Member::count()
{
    return counter;
}
