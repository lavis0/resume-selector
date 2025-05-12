#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../../include/Resume/ResumeData.h"
#include <sstream>
#include <stdexcept>

namespace ResumeEditor {

// Personal info management
const PersonalInfo& ResumeData::getPersonalInfo() const {
    return personalInfo_;
}

void ResumeData::setPersonalInfo(const PersonalInfo& info) {
    personalInfo_ = info;
}

// Experience management
const std::vector<Experience>& ResumeData::getExperiences() const {
    return experiences_;
}

void ResumeData::addExperience(const Experience& experience) {
    experiences_.push_back(experience);
}

void ResumeData::updateExperience(size_t index, const Experience& experience) {
    if (index >= experiences_.size()) {
        throw std::out_of_range("Experience index out of range");
    }
    experiences_[index] = experience;
}

void ResumeData::removeExperience(size_t index) {
    if (index >= experiences_.size()) {
        throw std::out_of_range("Experience index out of range");
    }
    experiences_.erase(experiences_.begin() + index);
}

void ResumeData::selectExperience(size_t index, bool selected) {
    if (index >= experiences_.size()) {
        throw std::out_of_range("Experience index out of range");
    }
    experiences_[index].setSelected(selected);
}

std::vector<Experience> ResumeData::getSelectedExperiences() const {
    std::vector<Experience> selected;
    for (const auto& exp : experiences_) {
        if (exp.isSelected()) {
            selected.push_back(exp);
        }
    }
    return selected;
}

} // namespace ResumeEditor