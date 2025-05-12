//
// Created by joshua on 09/05/2025.
//

#ifndef PERSONALINFO_H
#define PERSONALINFO_H

#include <string>

namespace ResumeEditor {

class PersonalInfo final {
public:
    PersonalInfo() = default;
    PersonalInfo(std::string name,
        std::string email,
        std::string phone,
        std::string linkedIn,
        std::string github,
        std::string website);

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
    bool isValidEmail() const;
    bool isValidPhone() const;

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
