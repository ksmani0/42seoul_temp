#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _totalNbDeposits = initial_deposit;
}


int	Account::getNbAccounts(void)
{//static 멤버함수도 static 멤버변수처럼 외부 정의 땐 static 떼기
    return Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
    //
}

void	Account::_displayTimestamp( void )
{
    time_t timeStamp;
    time(&timeStamp);

    std::cout << "[" << "]";
}