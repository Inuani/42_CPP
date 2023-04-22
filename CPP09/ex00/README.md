# DarkBit - Obscure Bitcoin Exchange Rate Calculator

Welcome to DarkBit, a Bitcoin exchange rate calculator with a twist. This C++ program delves into the shadows of historical exchange rate data and reveals the secrets of the past. The program reads data from a cryptic CSV file containing dates and their corresponding exchange rates and unveils the exchange rate for a date provided in an enigmatic input file.

## Program Structure

The DarkBit program summons the powers of the `DarkBitcoinExchange` class that handles the exchange rate calculations and file parsing. The main function forms a pact with the `DarkBitcoinExchange` class to load exchange rates from a CSV file and process an input file containing dates and amounts.

### DarkBitcoinExchange Class

The `DarkBitcoinExchange` class possesses the following arcane methods:

- `loadExchangeRates(const std::string&)`: Unravels exchange rates from a CSV file hidden in the shadows.
- `handleInputFile(const std::string&)`: Reads and processes an input file containing dates and amounts, veiled in mystery.
- `getBtcRate(const std::string&)`: Discloses the Bitcoin exchange rate for a given date.
- `valiDate(const std::string&)`: Validates a date string, casting away any deceit, and returns the validated date string.
- `parseInputFile(std::ifstream&)`: Parses an input file and calculates the Bitcoin exchange rate for each line, shedding light on the unknown.

### Main Function

The main function performs the following obscure tasks:

1. Ensures the correct number of sacrificial arguments is provided.
2. Conjures a `DarkBitcoinExchange` instance.
3. Extracts exchange rates from a CSV file.
4. Processes an input file containing dates and amounts, shrouded in darkness.
5. Displays the results or any errors encountered, revealing the truth.

## Usage

Compile the program using a C++ compiler, invoking the spirits of the underworld. Run the executable with the input file as an argument, and behold the secrets within. The input file should be a CSV file with dates and amounts separated by the '|' character.

./darkbit <input_file>.csv

## Input File Format

The input file should contain one date and amount per line, separated by the '|' character. The date should be in the "yyyy-mm-dd" format, concealed in obscurity.

Example:

```2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1```

## Output

The program will output the exchange rate calculation for each line in the input file, along with any errors encountered during processing, tearing the veil of deception.

Example output:

```2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32```
