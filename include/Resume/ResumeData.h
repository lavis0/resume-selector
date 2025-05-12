//
// Created by joshua on 09/05/2025.
//

#ifndef RESUMEDATA_H
#define RESUMEDATA_H

#include "PersonalInfo.h"
#include "Experience.h"
#include "Project.h"
#include "Skill.h"

#include <vector>

namespace ResumeEditor {

class ResumeData {
private:
    PersonalInfo personalInfo_;
    std::vector<Experience> experiences_;
    std::vector<Project> projects_;
    std::vector<Skill> skills_;

public:
    ResumeData() = default;
    ~ResumeData() = default;

    // Personal info management
    const PersonalInfo& getPersonalInfo() const;
    void setPersonalInfo(const PersonalInfo& info);

    // Experience management
    const std::vector<Experience>& getExperiences() const;
    void addExperience(const Experience& experience);
    void updateExperience(size_t index, const Experience& experience);
    void removeExperience(size_t index);
    void selectExperience(size_t index, bool selected);
    std::vector<Experience> getSelectedExperiences() const;


};

}

#endif //RESUMEDATA_H
