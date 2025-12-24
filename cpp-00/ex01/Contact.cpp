#include "Contact.hpp"

//conostructor
Contact::Contact() {
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setfirstname(std::string name)
{
    if (!name.empty())
        firstName = name;
}
void Contact::setlastname(std::string name)
{
    if (!name.empty())
        lastName = name;
}
void Contact::setnickname(std::string name)
{
    if (!name.empty())
        nickname = name;
}
void Contact::setphonenum(std::string num)
{
    if (!num.empty())
        phoneNumber = num;
}
void Contact::setdarkestsecret(std::string secret)
{
    if (!secret.empty())
        darkestSecret = secret;
}

// getters :
std::string Contact::getfirstname()
{
    return firstName;
}
std::string Contact::getlastname()
{
    return lastName;
}
std::string Contact::getnickname()
{
    return nickname;
}
std::string Contact::getphonenum()
{
    return phoneNumber;
}
std::string Contact::getdarkestsecret()
{
    return darkestSecret;
}
