//
// Created by joshua on 09/05/2025.
//

#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <string>
#include <regex>

namespace ResumeEditor {

class PersonalInfo final {
public:
    PersonalInfo() = default;
    PersonalInfo(std::string name,
                std::string email,
                std::string phone,
                std::string linkedIn,
                std::string github,
                std::string website)
        : name(std::move(name)), 
        email(std::move(email)), 
        phone(std::move(phone)),
        linkedIn(std::move(linkedIn)), 
        github(std::move(github)), 
        website(std::move(website)) {}

    virtual ~PersonalInfo() = default;

    /// getters and setters
    std::string getName() const {
        return name;
    }
    void setName(const std::string& name) {
        this->name = name;
    }

    std::string getEmail() const {
        return email;
    }
    void setEmail(const std::string& email) {
        this->email = email;
    }

    std::string getPhone() const {
        return phone;
    }
    void setPhone(const std::string& phone) {
        this->phone = phone;
    }

    std::string getLinkedIn() const {
        return linkedIn;
    }
    void setLinkedIn(const std::string& linkedIn) {
        this->linkedIn = linkedIn;
    }

    std::string getGithub() const {
        return github;
    }
    void setGithub(const std::string& github) {
        this->github = github;
    }

    std::string getWebsite() const {
        return website;
    }
    void setWebsite(const std::string& website) {
        this->website = website;
    }

    /// validation
    bool isValidEmail() const {
    if (email.empty()) return false;
    
    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailPattern);
    }

    bool isValidPhone() const {
        if (phone.empty()) return false;
        
        std::regex phonePattern(R"((\(\d{3}\)|\d{3})[-\s]?\d{3}[-\s]?\d{4})");
        return std::regex_match(phone, phonePattern);
    }

private:
    std::string name;
    std::string email;
    std::string phone;
    std::string linkedIn;
    std::string github;
    std::string website;
};

}

#endif //PERSONALINFO_H
