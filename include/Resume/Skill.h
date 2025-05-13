//
// Created by joshua on 09/05/2025.
//

#ifndef SKILL_H
#define SKILL_H

#include <string>

/* TODO:
 * - testing
 */

namespace ResumeEditor {

enum class SkillLevel {
    Beginner,
    Intermediate,
    Advanced,
    Expert
};

class Skill {
public:
    Skill() = default;
    Skill(const std::string& name, SkillLevel level = SkillLevel::Intermediate,
          bool selected = false) {
        setName(name);
        setLevel(level);
        setSelected(selected);
    }

    // Getters and setters
    const std::string& getName() const {
        return name_;
    }
    void setName(const std::string& name) {
        this->name_ = name;
    }

    SkillLevel getLevel() const {
        return level_;
    }
    void setLevel(const SkillLevel level) {
        this->level_ = level;
    }

    bool isSelected() const {
        return selected_;
    }
    void setSelected(const bool selected) {
        this->selected_ = selected;
    }

    // Utility methods
    std::string getLevelAsString() const {
        switch (level_) {
            case SkillLevel::Beginner:
                return "Beginner";
            case SkillLevel::Intermediate:
                return "Intermediate";
            case SkillLevel::Advanced:
                return "Advanced";
            case SkillLevel::Expert:
                return "Expert";
        }
        return nullptr; // TODO: exception
    }

private:
    std::string name_;
    SkillLevel level_;
    bool selected_;
};

} // namespace ResumeEditor


#endif //SKILL_H
