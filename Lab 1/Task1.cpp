#include<iostream>

class BankAccount
{
    private:
        int balance;
    
    public:
        BankAccount(int initAmount): balance(initAmount){};

        BankAccount(BankAccount &other)
        {
            balance = other.balance;
        };

        void withdraw(int amount)
        {
            if (amount <= balance)
                balance -= amount;
            else
                printf("INSUFFICENT AMOUNT...\n");
        }

        void add_amount(int amount)
        {
            balance += amount;
        }

        void show_balance()
        {
            printf("Remaining Amount: $%d\n", balance);
        }
};

int main()
{
    BankAccount account1(500);
    account1.show_balance();

    BankAccount account2(1000);
    account2.show_balance();

    BankAccount account3(account2);
    account3.withdraw(200);

    printf("Amount in Account 2\n");
    account2.show_balance();

    printf("Amount in Account 3\n");
    account3.show_balance();


}