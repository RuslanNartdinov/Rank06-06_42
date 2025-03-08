#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);
	std::cout << "["
			  << 1900 + ltm->tm_year
			  << ((ltm->tm_mon + 1) < 10 ? "0" : "") << ltm->tm_mon + 1
			  << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
			  << "_"
			  << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
			  << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
			  << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
			  << "]";
}
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";p_amount:" << this->_amount;

	if (this->_amount < withdrawal)
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

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts
			  << ";total:" << Account::_totalAmount
			  << ";deposits:" << Account::_totalNbDeposits
			  << ";withdrawals:" << Account::_totalNbWithdrawals
			  << std::endl;
}