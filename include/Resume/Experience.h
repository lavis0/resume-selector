#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>

/// TODO:
/// - validation
/// - unit testing

namespace ResumeEditor {
class Experience final {
private:
    std::string title_;
    std::string company_;
    std::string location_;
    std::string startDate_;
    std::string endDate_;
    std::unordered_set<std::string> description_;
    bool selected_;

    // validation
    // Validates a single description string
    static void isValidDescription(const std::string& description) {
        if (description.empty()) {
            throw std::invalid_argument("Description cannot be empty.");
        }

        if (description.length() > 160) {
            throw std::invalid_argument("Description is too long.");
        }
    }

    // Validates an entire vector of descriptions
    static void isValidDescriptionList(const std::vector<std::string>& descriptions) {
        if (descriptions.empty()) {
            throw std::invalid_argument("Description list cannot be empty.");
        }
        for (const auto& singleDescription : descriptions) {
            isValidDescription(singleDescription);
        }
    }

public:
    Experience() = default;
    Experience(const std::string& title, const std::string& company,
        const std::string& location, const std::string& startDate,
        const std::string& endDate, const std::vector<std::string>& description) {
        setTitle(title);
        setCompany(company);
        setLocation(location);
        setStartDate(startDate);
        setEndDate(endDate);
        setDescription(description);
        setSelected(false);
    }
    virtual ~Experience() = default;

    // setters, getters and validation
    void setTitle(const std::string& title) {
        this->title_ = title;
    }
    const std::string& getTitle() const {
        return title_;
    }

    void setCompany(const std::string& company) {
        this->company_ = company;
    }
    const std::string& getCompany() const {
        return company_;
    }

    void setLocation(const std::string& location) {
        this->location_ = location;
    }
    const std::string& getLocation() const {
        return location_;
    }

    void setStartDate(const std::string& startDate) {
        this->startDate_ = startDate;
    }
    const std::string& getStartDate() const {
        return startDate_;
    }

    void setEndDate(const std::string& endDate) {
        this->endDate_ = endDate;
    }
    const std::string& getEndDate() const {
        return endDate_;
    }

    void setDescription(const std::vector<std::string>& descriptions) {
        isValidDescriptionList(descriptions);
        
        this->description_.clear();
        for (const auto& desc : descriptions) {
            this->description_.insert(desc);
        }
    }
    
    std::unordered_set<std::string> getDescription() const {
        return this->description_;
    }
    
    void addDescription(const std::string& description) {
        isValidDescription(description);
        
        auto result = this->description_.insert(description);
        if (!result.second) {
            throw std::invalid_argument("Description already exists.");
        }
    }
    
    void removeDescription(const std::string& descriptionToRemove) {
        auto count = this->description_.erase(descriptionToRemove);
        if (count == 0) {
            throw std::out_of_range("Description not found: " + descriptionToRemove);
        }
    }

    bool isSelected() const {
        return this->selected_;
    }
    void setSelected(bool selected) {
        this->selected_ = selected;
    }
};
} // namespace ResumeEditor 

#endif //EXPERIENCE_H
