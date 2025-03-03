# Air Force Mission Assets 🚀

Welcome to the **Air Force Mission Assets**, a C++ project designed to showcase Object-Oriented Programming (OOP) concepts and explore advanced software design techniques. This project includes two major parts, both focusing on different aspects of OOP, to help deepen understanding and demonstrate practical applications in a real-world-like scenario.

📝 **Description**  
The **Air Force Mission Assets** project is a combination of two smaller projects that work together to manage military aircraft and flight operations. The first part of the project focuses on diamond inheritance and multiple classes, tackling the complexities of aircraft hierarchy and crew management. The second part utilizes design patterns like Singleton and Template classes, alongside STL containers like `vector`, `map` and `set`, to manage fleet data and operations effectively.

✨ **Key Features**  

### **First Project: Aircraft & Crew Management**
- **Diamond Inheritance**:  
  - Demonstrates the use of diamond inheritance to manage different aircraft types such as Fighter Jets, Recon Aircraft, and Multi-role Aircraft.
  - **Avion** is the base class with multiple derived classes, allowing efficient use of inheritance.
- **Pilot Management**:  
  - The **Pilot** class tracks pilot experience, ratings, and nationalities.
  - Dynamic crew assignments to different aircraft based on pilot capabilities.
- **Performance Scoring**:  
  - Calculate pilot efficiency scores and filter pilots based on performance.
- **Aircraft Fleet Management**:  
  - Allows sorting of aircraft by attributes like wingspan, manufacturing year, and performance.
  
### **Second Project: Fleet Management with Advanced Techniques**
- **Singleton Design Pattern**:  
  - Used for the **Menu** class to ensure only one instance of the menu exists throughout the application.
- **Template Class**:  
  - **Aeroport<T>** is used to handle type-safe fleet management, ensuring flexibility and reusability.
- **STL Containers**:  
  - Used to manage data efficiently, with `map`, `set`, and `vector` for organizing aircraft and crew data.

- **Error Handling**:
  - Used to manage invalid inputs and prevent operations on non-existing objects, ensuring smooth application execution.

### **Common Features in Both Projects**
- **CRUD Operations**:  
  - Add, update, and delete both aircraft and pilots, allowing for efficient management.
- **Polymorphism**:  
  - Used to handle different types of aircraft, pilot assignments, and operations dynamically, enabling method overriding for specific behaviors in derived classes, and applied to template functions and classes for type-safe, flexible operations.
- **Interactive CLI Interface**:  
  - Provides an easy-to-use interface for interacting with the program and performing necessary operations.
  

