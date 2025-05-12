//
// Created by joshua on 09/05/2025.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <sstream>

#include "Resume/ResumeData.h"
#include "Resume/Experience.h"
#include "Resume/PersonalInfo.h"

using namespace ResumeEditor;

// Forward declarations
void printHelp();
void displayPersonalInfo(const PersonalInfo& info);
void displayExperience(const Experience& exp, size_t index);
void displayExperienceDetails(const Experience& exp);
void addExperience(ResumeData& resumeData);
void editExperience(ResumeData& resumeData, size_t index);
void setPersonalInfoField(PersonalInfo& info, const std::string& field, const std::string& value);
void addDescription(ResumeData& resumeData, size_t index, const std::string& text);
void removeDescription(ResumeData& resumeData, size_t index, const std::string& text);

int main(int argc, char* argv[]) {
    ResumeData resumeData;
    std::string command;
    
    // Initialize with some default personal info
    PersonalInfo info;
    info.setName("Your Name");
    info.setEmail("your.email@example.com");
    info.setPhone("123-456-7890");
    info.setLinkedIn("linkedin.com/in/yourprofile");
    info.setGithub("github.com/yourusername");
    info.setWebsite("yourdomain.com");
    resumeData.setPersonalInfo(info);
    
    std::cout << "Welcome to Resume Selector CLI!" << std::endl;
    std::cout << "Type 'help' for available commands, 'exit' to quit." << std::endl;
    
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        
        // Split the command into tokens
        std::istringstream iss(command);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        
        if (tokens.empty()) {
            continue;
        }
        
        if (tokens[0] == "exit") {
            break;
        } else if (tokens[0] == "help") {
            printHelp();
        } else if (tokens[0] == "info") {
            if (tokens.size() == 1) {
                displayPersonalInfo(resumeData.getPersonalInfo());
            } else if (tokens.size() >= 4 && tokens[1] == "set") {
                std::string value = tokens[3];
                for (size_t i = 4; i < tokens.size(); i++) {
                    value += " " + tokens[i];
                }
                PersonalInfo updatedInfo = resumeData.getPersonalInfo();
                setPersonalInfoField(updatedInfo, tokens[2], value);
                resumeData.setPersonalInfo(updatedInfo);
            } else {
                std::cout << "Invalid command. Try 'help' for usage.\n";
            }
        } else if (tokens[0] == "exp") {
            if (tokens.size() < 2) {
                std::cout << "Invalid command. Try 'help' for usage.\n";
                continue;
            }
            
            if (tokens[1] == "list") {
                const auto& experiences = resumeData.getExperiences();
                if (experiences.empty()) {
                    std::cout << "No experiences available.\n";
                } else {
                    std::cout << "Experiences:\n";
                    for (size_t i = 0; i < experiences.size(); i++) {
                        displayExperience(experiences[i], i);
                    }
                }
            } else if (tokens[1] == "add") {
                addExperience(resumeData);
            } else if (tokens[1] == "view" && tokens.size() > 2) {
                try {
                    size_t index = std::stoul(tokens[2]);
                    const auto& experiences = resumeData.getExperiences();
                    if (index >= experiences.size()) {
                        std::cout << "Invalid experience index.\n";
                    } else {
                        displayExperienceDetails(experiences[index]);
                    }
                } catch (const std::exception&) {
                    std::cout << "Invalid index format.\n";
                }
            } else if (tokens[1] == "edit" && tokens.size() > 2) {
                try {
                    size_t index = std::stoul(tokens[2]);
                    editExperience(resumeData, index);
                } catch (const std::exception&) {
                    std::cout << "Invalid index format.\n";
                }
            } else if (tokens[1] == "delete" && tokens.size() > 2) {
                try {
                    size_t index = std::stoul(tokens[2]);
                    if (index >= resumeData.getExperiences().size()) {
                        std::cout << "Invalid experience index.\n";
                    } else {
                        resumeData.removeExperience(index);
                        std::cout << "Experience deleted successfully.\n";
                    }
                } catch (const std::exception&) {
                    std::cout << "Invalid index format.\n";
                }
            } else if (tokens[1] == "select" && tokens.size() > 2) {
                try {
                    size_t index = std::stoul(tokens[2]);
                    if (index >= resumeData.getExperiences().size()) {
                        std::cout << "Invalid experience index.\n";
                    } else {
                        resumeData.selectExperience(index, true);
                        std::cout << "Experience marked as selected.\n";
                    }
                } catch (const std::exception&) {
                    std::cout << "Invalid index format.\n";
                }
            } else if (tokens[1] == "deselect" && tokens.size() > 2) {
                try {
                    size_t index = std::stoul(tokens[2]);
                    if (index >= resumeData.getExperiences().size()) {
                        std::cout << "Invalid experience index.\n";
                    } else {
                        resumeData.selectExperience(index, false);
                        std::cout << "Experience marked as not selected.\n";
                    }
                } catch (const std::exception&) {
                    std::cout << "Invalid index format.\n";
                }
            } else if (tokens[1] == "selected") {
                const auto& selected = resumeData.getSelectedExperiences();
                if (selected.empty()) {
                    std::cout << "No experiences are currently selected.\n";
                } else {
                    std::cout << "Selected Experiences:\n";
                    for (size_t i = 0; i < selected.size(); i++) {
                        displayExperience(selected[i], i);
                    }
                }
            } else if (tokens[1] == "desc" && tokens.size() >= 5) {
                try {
                    size_t index = std::stoul(tokens[3]);
                    
                    // Combine all remaining tokens for the description text
                    std::string text = tokens[4];
                    for (size_t i = 5; i < tokens.size(); i++) {
                        text += " " + tokens[i];
                    }
                    
                    if (tokens[2] == "add") {
                        addDescription(resumeData, index, text);
                    } else if (tokens[2] == "remove") {
                        removeDescription(resumeData, index, text);
                    } else {
                        std::cout << "Invalid command. Use 'exp desc add' or 'exp desc remove'.\n";
                    }
                } catch (const std::invalid_argument&) {
                    std::cout << "Invalid index format.\n";
                } catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << "\n";
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << "\n";
                }
            } else {
                std::cout << "Invalid command. Try 'help' for usage.\n";
            }
        } else {
            std::cout << "Unknown command. Try 'help' for usage.\n";
        }
    }
    
    return 0;
}

// Helper Functions Implementation

void printHelp() {
    std::cout << "Resume Selector CLI\n"
              << "====================\n"
              << "Available commands:\n"
              << "  help                          - Display this help message\n"
              << "  exit                          - Exit the application\n"
              << "  info                          - Display personal information\n"
              << "  info set <field> <value>      - Set personal information field\n"
              << "                                  (fields: name, email, phone, linkedin, github, website)\n"
              << "  exp list                      - List all experiences\n"
              << "  exp add                       - Add a new experience (interactive)\n"
              << "  exp view <index>              - View details of an experience\n"
              << "  exp edit <index>              - Edit an experience (interactive)\n"
              << "  exp delete <index>            - Delete an experience\n"
              << "  exp select <index>            - Mark an experience as selected\n"
              << "  exp deselect <index>          - Mark an experience as not selected\n"
              << "  exp selected                  - Show all selected experiences\n"
              << "  exp desc add <index> <text>   - Add description to an experience\n"
              << "  exp desc remove <index> <text>- Remove description from an experience\n"
              << std::endl;
}

void displayPersonalInfo(const PersonalInfo& info) {
    std::cout << "Personal Information:\n"
              << "--------------------\n"
              << "Name: " << info.getName() << "\n"
              << "Email: " << info.getEmail() << "\n"
              << "Phone: " << info.getPhone() << "\n"
              << "LinkedIn: " << info.getLinkedIn() << "\n"
              << "GitHub: " << info.getGithub() << "\n"
              << "Website: " << info.getWebsite() << "\n"
              << std::endl;
}

void displayExperience(const Experience& exp, size_t index) {
    std::cout << index << ". " << exp.getTitle() << " at " << exp.getCompany() 
              << " (" << exp.getStartDate() << " - " << exp.getEndDate() << ") "
              << (exp.isSelected() ? "[SELECTED]" : "") << "\n";
}

void displayExperienceDetails(const Experience& exp) {
    std::cout << "Title: " << exp.getTitle() << "\n"
              << "Company: " << exp.getCompany() << "\n"
              << "Location: " << exp.getLocation() << "\n"
              << "Period: " << exp.getStartDate() << " - " << exp.getEndDate() << "\n"
              << "Selected: " << (exp.isSelected() ? "Yes" : "No") << "\n"
              << "Description: " << "\n";
    
    for (const auto& desc : exp.getDescription()) {
        std::cout << "  - " << desc << "\n";
    }
    std::cout << std::endl;
}

void addExperience(ResumeData& resumeData) {
    std::string title, company, location, startDate, endDate;
    std::vector<std::string> descriptions;
    std::string description;
    
    std::cout << "Enter experience details:\n";
    
    std::cout << "Title: ";
    std::getline(std::cin, title);
    
    std::cout << "Company: ";
    std::getline(std::cin, company);
    
    std::cout << "Location: ";
    std::getline(std::cin, location);
    
    std::cout << "Start Date: ";
    std::getline(std::cin, startDate);
    
    std::cout << "End Date (leave empty for 'Present'): ";
    std::getline(std::cin, endDate);
    if (endDate.empty()) endDate = "Present";
    
    std::cout << "Enter descriptions (one per line, empty line to finish):\n";
    while (true) {
        std::cout << "- ";
        std::getline(std::cin, description);
        if (description.empty()) break;
        descriptions.push_back(description);
    }
    
    if (descriptions.empty()) {
        std::cout << "At least one description is required. Experience not added.\n";
        return;
    }
    
    try {
        Experience exp(title, company, location, startDate, endDate, descriptions);
        resumeData.addExperience(exp);
        std::cout << "Experience added successfully.\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Error adding experience: Invalid data - " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error adding experience: " << e.what() << "\n";
    }
}

void editExperience(ResumeData& resumeData, size_t index) {
    if (index >= resumeData.getExperiences().size()) {
        std::cout << "Invalid experience index.\n";
        return;
    }
    
    const Experience& oldExp = resumeData.getExperiences()[index];
    std::string title = oldExp.getTitle();
    std::string company = oldExp.getCompany();
    std::string location = oldExp.getLocation();
    std::string startDate = oldExp.getStartDate();
    std::string endDate = oldExp.getEndDate();
    
    // Convert unordered_set to vector for editing
    std::vector<std::string> descriptions(oldExp.getDescription().begin(), oldExp.getDescription().end());
    
    std::string input;
    
    std::cout << "Editing experience " << index << " (press Enter to keep current value):\n";
    
    std::cout << "Title [" << title << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) title = input;
    
    std::cout << "Company [" << company << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) company = input;
    
    std::cout << "Location [" << location << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) location = input;
    
    std::cout << "Start Date [" << startDate << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) startDate = input;
    
    std::cout << "End Date [" << endDate << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) endDate = input;
    
    char descChoice;
    std::cout << "Edit descriptions? (y/n): ";
    std::cin >> descChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (descChoice == 'y' || descChoice == 'Y') {
        descriptions.clear();
        std::string description;
        std::cout << "Enter descriptions (one per line, empty line to finish):\n";
        while (true) {
            std::cout << "- ";
            std::getline(std::cin, description);
            if (description.empty()) break;
            descriptions.push_back(description);
        }
        
        if (descriptions.empty()) {
            std::cout << "At least one description is required. Using previous descriptions.\n";
            descriptions.assign(oldExp.getDescription().begin(), oldExp.getDescription().end());
        }
    }
    
    try {
        Experience exp(title, company, location, startDate, endDate, descriptions);
        exp.setSelected(oldExp.isSelected());
        resumeData.updateExperience(index, exp);
        std::cout << "Experience updated successfully.\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Error updating experience: Invalid data - " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error updating experience: " << e.what() << "\n";
    }
}

void setPersonalInfoField(PersonalInfo& info, const std::string& field, const std::string& value) {
    if (field == "name") {
        info.setName(value);
    } else if (field == "email") {
        info.setEmail(value);
    } else if (field == "phone") {
        info.setPhone(value);
    } else if (field == "linkedin") {
        info.setLinkedIn(value);
    } else if (field == "github") {
        info.setGithub(value);
    } else if (field == "website") {
        info.setWebsite(value);
    } else {
        std::cout << "Unknown field: " << field << "\n";
        std::cout << "Valid fields are: name, email, phone, linkedin, github, website\n";
        return;
    }
    std::cout << "Personal info updated successfully.\n";
}

void addDescription(ResumeData& resumeData, size_t index, const std::string& text) {
    if (index >= resumeData.getExperiences().size()) {
        throw std::out_of_range("Experience index out of range");
    }
    
    // We need to create a copy as getExperiences() returns const references
    Experience exp = resumeData.getExperiences()[index];
    exp.addDescription(text);
    resumeData.updateExperience(index, exp);
    std::cout << "Description added successfully.\n";
}

void removeDescription(ResumeData& resumeData, size_t index, const std::string& text) {
    if (index >= resumeData.getExperiences().size()) {
        throw std::out_of_range("Experience index out of range");
    }
    
    // We need to create a copy as getExperiences() returns const references
    Experience exp = resumeData.getExperiences()[index];
    exp.removeDescription(text);
    resumeData.updateExperience(index, exp);
    std::cout << "Description removed successfully.\n";
}