//
// Created by joshua on 09/05/2025.
//

#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>

/* TODO:
 * - validation
 * - testing
 */

namespace ResumeEditor {

class Project {
public:
    Project() = default;
    Project(const std::string& name, const std::string& description,
            const std::unordered_set<std::string>& technologies, bool selected = false) {
        setName(name);
        setDescription(description);
        setTechnologies(technologies);
        setSelected(selected);
    }

    // Getters and setters
    const std::string& getName() const {
        return name_;
    }
    void setName(const std::string& name) {
        this->name_ = name;
    }

    const std::string& getRepo() const {
        return repo_;
    }
    void setRepo(const std::string& repo) {
        this->repo_ = repo;
    }

    const std::string& getDescription() const {
        return description_;
    }
    void setDescription(const std::string& description) {
        this->description_ = description;
    }

    const std::unordered_set<std::string>& getTechnologies() const {
        return technologies_;
    }
    void setTechnologies(const std::unordered_set<std::string>& technologies) {
        this->technologies_ = technologies;
    }
    void addTechnology(const std::string& technology) {
        this->technologies_.insert(technology);
    }
    void removeTechnology(const std::string& technology) {
        this->technologies_.erase(technology);
    }

    bool isSelected() const {
        return selected_;
    }
    void setSelected(bool selected) {
        this->selected_ = selected;
    }

    // Utility methods
    std::string getTechnologiesAsString(const std::string& separator = ", ") const {
        std::string result;
        for (const auto& tech : technologies_) {
            result += tech + separator;
        }
        return result;
    }

private:
    std::string name_;
    std::string repo_;
    std::string description_;
    std::unordered_set<std::string> technologies_;
    bool selected_ = false;
};

} // namespace ResumeEditor


#endif //PROJECT_H
