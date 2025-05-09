<div align="center">
  <h1>Resume Selector</h1>

  <p>
    A C++/Qt application for creating customized resumes by selecting relevant experience
    <br />
    <a href="docs/user_guide.md"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="#demo">View Demo</a>
    ·
    <a href="https://github.com/lavis0/resume_selector/issues">Report Bug</a>
    ·
    <a href="https://github.com/lavis0/resume_selector/issues">Request Feature</a>
  </p>
</div>

## About The Project

Resume Selector is a desktop application that simplifies the process of tailoring your résumé to specific job applications. By maintaining a database of all your experiences, projects, and skills, you can quickly select the most relevant items and generate a professional PDF résumé using LaTeX templates.

### Key Features

* Import/export your experience data from/to CSV files
* Check boxes to select relevant experiences for each job application
* Generate professional-looking resume PDFs using LaTeX templates
* Save different configurations for different job applications
* Clean, intuitive user interface built with Qt

### Built With

* [C++20](https://en.cppreference.com/w/cpp/20)
* [Qt](https://www.qt.io/)
* [LaTeX](https://www.latex-project.org/)
* [GTest](https://github.com/google/googletest)

## Getting Started

To get a local copy up and running, follow these steps.

### Prerequisites

* CMake (version 3.31 or later)
* C++ compiler with C++20 support
* Qt 6 (for GUI version)
* LaTeX distribution (for PDF generation)

### Installation

1. Clone the repository
   ```sh
   git clone https://github.com/yourusername/resume_selector.git
   ```
2. Create a build directory
   ```sh
   mkdir -p resume_selector/build
   cd resume_selector/build
   ```
3. Configure with CMake
   ```sh
   cmake ..
   ```
4. Build the project
   ```sh
   cmake --build .
   ```

## Usage

### Command Line Version

The application initially comes with a command-line interface for testing the core functionality:

```sh
./resume-cli --load myexperience.csv --select "Software Engineer" --output resume.pdf
```

### GUI Version (Coming Soon)
Once the Qt interface is implemented:
1. Launch the application
2. Import your experience data or create a new profile
3. Select relevant experiences for your target job
4. Generate a PDF resume
5. Save your selection for future use

_For more examples and usage instructions, please refer to the [Documentation](docs/user_guide.md)_
## Project Structure
The project follows an object-oriented design with a clear separation of concerns:
``` 
resume_selector/
├── include/              # Public header files
│   ├── Common/           # Common utilities
│   ├── Resume/           # Core data models
│   ├── Storage/          # CSV handling
│   ├── LaTeX/            # PDF generation
│   └── UI/               # Qt interface (future)
├── lib/                  # Implementation files
├── src/                  # Executable entry points
├── tests/                # Unit tests
└── resources/            # Application resources
```
## Roadmap
- [x] Project initialization
- [ ] Core data model implementation
- [ ] CSV import/export functionality
- [ ] LaTeX generation and PDF output
- [ ] Command-line interface
- [ ] Qt GUI implementation
- [ ] Multiple resume template support
- [ ] Application settings and preferences

See the [open issues](https://github.com/lavis0/resume_selector/issues) for a full list of proposed features and known issues.
## Contributing
Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.
1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License
Distributed under the MIT License. See `LICENSE` for more information.

## Contact
Joshua - [@LinkedIn](https://linkedin.com/joshua-banga) - josh@folient.com

Project Link: [https://github.com/lavis0/resume_selector](https://github.com/yourusername/resume_selector)
## Acknowledgements
- [GTest](https://github.com/google/googletest) for testing
- [Qt](https://www.qt.io/) for the GUI framework
- [othneildrew](https://github.com/othneildrew/Best-README-Template) for the README template

