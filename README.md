# Financial Portfolio Management System

## Overview

This project is a financial portfolio management system that handles various financial instruments, including **bonds**, **stocks**, and **securities**. The system allows users to create portfolios, add different types of assets, and calculate income or value based on the input provided. It includes error handling for invalid inputs and ensures proper validation for financial and date-related data.

## Features

- **Bond Management**: Allows the creation of bonds with fields like par value, interest rate, and maturity date.
- **Stock Management**: Supports adding stocks with properties like ticker symbols, par value, number of shares, and dividend calculation.
- **Security Management**: Serves as a base class for all financial instruments, ensuring consistent behavior across different types of assets.
- **Portfolio Management**: Manages a collection of securities and computes total portfolio income or value.
- **Error Handling and Input Validation**: Validates inputs for interest rates, dates, and other numeric fields to prevent incorrect entries.

## Getting Started

### Prerequisites

To run this project, you'll need:

- A C++ compiler (e.g., g++, clang++).
- A terminal or command line environment for compiling and running the program.

### Compiling the Code

You can compile the project using the following command:

```bash
g++ -o portfolio portfolioDriver.cpp portfolio.cpp bond.cpp stock.cpp security.cpp -I.
```

### Running the Program

After compiling, you can run the executable with:

```bash
./portfolio
```
Follow the on-screen instructions to manage your financial portfolio.

## Input Format

- **Bonds**: Requires par value, stated interest rate (in decimal format), and maturity date (in mm/dd/yyyy format).
- **Stocks**: Requires ticker symbol, par value, stock type (common or preferred), dividends per share, and number of shares.
- **Quit Option**: The program will guide you through the steps for adding instruments. To exit at any point, follow the prompts in the program.

## Code Structure

- **`bond.cpp` and `bond.h`**: Handles bond-related functionality, including input validation and income calculation.
- **`stock.cpp` and `stock.h`**: Manages stock-related data such as ticker symbols, par value, dividends, and stock type.
- **`security.cpp` and `security.h`**: Base class for all financial instruments, ensuring consistent behavior across different assets.
- **`portfolio.cpp` and `portfolio.h`**: Implements portfolio management, allowing users to add securities and calculate overall income.
- **`portfolioDriver.cpp`**: The main entry point for the program, where user interaction occurs.

## Error Handling

- **Numeric Input**: The program checks for invalid numeric inputs (e.g., negative interest rates, out-of-range par values).
- **Date Input**: Dates are expected in `mm/dd/yyyy` format. If the format is incorrect, the program will ask for re-entry.
- **Dividends and Shares**: Dividends and share numbers must be positive values.

## Future Improvements

- **More Financial Instruments**: Add support for additional instruments such as ETFs, mutual funds, or options.
- **Advanced Error Handling**: Implement advanced error handling for more complex inputs, such as parsing multiple date formats or handling edge cases in financial data.
- **Graphical Interface**: Develop a user-friendly GUI for managing the portfolio instead of relying on terminal input.

## License

This project is licensed under the MIT License. See the [MIT LICENSE](LICENSE) for more details.