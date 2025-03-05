#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip> // for setw, setfill if needed

// ------------------------------------------------------------------
// Static member variables definition
// ------------------------------------------------------------------
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// ------------------------------------------------------------------
// Private default constructor (never called in the usual tests)
// ------------------------------------------------------------------
Account::Account( void )
{
    // Not used in this exercise, but must exist because it's declared private
}

// ------------------------------------------------------------------
// Public constructor with initial deposit
// ------------------------------------------------------------------
Account::Account( int initial_deposit ) :
    _accountIndex(Account::_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

// ------------------------------------------------------------------
// Destructor
// ------------------------------------------------------------------
Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}

// ------------------------------------------------------------------
// Static getters
// ------------------------------------------------------------------
int Account::getNbAccounts( void )
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

// ------------------------------------------------------------------
// Display general account info (all accounts combined)
// ------------------------------------------------------------------
void Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals()
              << std::endl;
}

// ------------------------------------------------------------------
// Make a deposit
// ------------------------------------------------------------------
void Account::makeDeposit( int deposit )
{
    int p_amount = this->_amount;

    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

// ------------------------------------------------------------------
// Attempt to make a withdrawal
// ------------------------------------------------------------------
bool Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount;

    if (withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;
    return true;
}

// ------------------------------------------------------------------
// Check account amount (returns current balance)
// ------------------------------------------------------------------
int Account::checkAmount( void ) const
{
    return this->_amount;
}

// ------------------------------------------------------------------
// Display the status of a single account
// ------------------------------------------------------------------
void Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

// ------------------------------------------------------------------
// Static: display current timestamp in [YYYYMMDD_HHMMSS] format
// ------------------------------------------------------------------
void Account::_displayTimestamp( void )
{
    // Example format: [19920104_091532]
    // The subject's examples often use this exact format, but as long
    // as you produce some bracketed time, you're typically fine.
    time_t      now = time(NULL);
    struct tm*  tstruct = localtime(&now);

    std::cout << "[" << (tstruct->tm_year + 1900);
    std::cout << std::setw(2) << std::setfill('0') << tstruct->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << tstruct->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << tstruct->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << tstruct->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << tstruct->tm_sec;
    std::cout << "]";
}