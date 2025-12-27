# Contacts

A C console address book with a Chinese-language menu.

## Build

Open `通讯录.sln` in Visual Studio 2022 with Desktop development with
C++ installed. Select Debug or Release and x64 or x86, then build the solution.
Run the generated `通讯录.exe` from a writable working directory.

## Commands

- 1 adds a contact. Enter the name, age, gender, phone number, and address in order.
- 2 deletes a contact by name.
- 3 displays a contact by name.
- 4 replaces the fields of a contact found by name.
- 5 displays all contacts.
- 6 sorts the list by name.
- 0 saves the address book and exits.

Text inputs are whitespace-delimited. Name lookup matches the first exact name.

## Local data

The program reads and writes `contact.txt` in its working directory. The file
contains binary C records. Use the same build format when reopening the file.
The file may contain personal information and is excluded from Git.
