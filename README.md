<img src="plazza_logo.png" alt="Plazza Logo" width=250 height=250 align="right" />

# Plazza - Concurrent Pizza Ordering and Cooking Simulation

**Table of Contents**
- [Project Description](#project-description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Architecture](#architecture)
  - [The Reception](#the-reception)
  - [Kitchens](#kitchens)
  - [Pizzas](#pizzas)
- [Contributing](#contributing)
- [License](#license)

## Project Description

Plazza is a C++ project that simulates the operation of a pizzeria, including a reception that accepts pizza orders, multiple kitchens, each with several cooks, and the cooking of various types of pizzas.

The project aims to help understand and solve various challenges in concurrent programming, including load balancing, process and thread synchronization, and inter-process communication. 

It includes a command-line interface for ordering pizzas and managing the pizzeria.

### Compilation

The project can be compiled using the provided Makefile, which includes rules for building, cleaning, and removing unnecessary files.

```shell
make          # Compile the project
make re       # Recompile the project
make clean    # Clean up object files
make fclean   # Remove all compiled files, including the binary
```

The compiled binary is named `plazza`.

### Interactive Shell

The reception is an interactive shell where you can place pizza orders through the command line. It also displays the status of kitchens, including the number of cooks and ingredient stocks.

## Getting Started

### Compilation

To compile the project, use the provided Makefile:

```shell
make
```

## Usage

To run the Plazza project, use the following command:

```shell
./plazza <multiplier> <cooks-per-kitchen> <ingredient-replacement-time>
```

- `<multiplier>`: A multiplier for the cooking time of pizzas (0-1).
- `<cooks-per-kitchen>`: The number of cooks per kitchen.
- `<ingredient-replacement-time>`: Time in milliseconds for ingredient replacement.

## Project Structure

The project includes the following files and directories:

- `source/`: Source files
- `include/`: Header files
- `Makefile`: Compilation rules
- `plazza`: Compiled binary
- `plazza.png`: Plazza logo (optional)

## Architecture

### The Reception

The reception is started using command-line arguments. It's an interactive shell that accepts pizza orders and displays the status of kitchens. 

You can place orders with commands like `regina XXL x2; fantasia M x3; margarita S x1`.

### Kitchens

Kitchens are child processes of the reception. They are created as needed and have a fixed number of cooks represented by threads.

Kitchens communicate with the reception using IPC (here a message queue). They maintain ingredient stocks and open new kitchens if necessary.

### Pizzas

Pizzas are allocated to kitchens, and information about orders and pizzas is serialized and communicated through IPC. The project defines four types of pizzas (Margarita, Regina, Americana, Fantasia) and various sizes (S, M, L, XL, XXL).
