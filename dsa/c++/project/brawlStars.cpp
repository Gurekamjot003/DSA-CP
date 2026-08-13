#include <iostream>
using namespace std;

class currency
{
public:
    static int c;
    void add(int n) { c += n; }
    void display();
};

int currency::c;

class brawler
{
    string name;
    int baseHP;
    int ammo;
    int basedamage;
    int power;
    int HP;
    int damage;
    int projectiles;
    int upgradeCostCoins;
    int upgradeCostPowerPoints;

protected:
    int unlockCost = 0;

public:
    void setName(string s)
    {
        name = s;
    }
    void unlock()
    {
        if (currency::c > unlockCost)
        {
            currency::c -= unlockCost;
            power = 1;
            HP = baseHP;
            damage = basedamage;
        }
        else
        {
            cout << "Insufficient Credits" << endl;
        }
    }
    void upgrade()
    {
        if (power < 11)
        {
            power += 1;
            HP = baseHP + ((power - 1) * baseHP) / 10;
            damage = basedamage + ((power - 1) * basedamage) / 10;
        }
        else
        {
            cout << "Brawler already at max level " << endl;
        }
    }
    void setData(int a, int b, int c, int d)
    {
        baseHP = a;
        basedamage = b;
        projectiles = c;
        ammo = d;
    }
    void display()
    {
        cout << endl
             << "Brawler name: " << name << endl
             << "Power level: " << power << endl
             << "HP: " << HP << endl
             << "Damage: " << damage << endl
             << endl;
    }
};
class startingBrawler : public brawler
{
public:
    startingBrawler()
    {
        unlockCost = 0;
    }
};

class rare : public brawler
{
public:
};

class superRare : public brawler
{
};
class epic : public brawler
{
};
class mythic : public brawler
{
};
class legendary : public brawler
{
};
class chromatic : public brawler
{
};

int main()
{
    startingBrawler shelly;
    shelly.setName("Shelly");
    shelly.setData(3700, 300, 5, 3);
    shelly.unlock();
    shelly.display();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.upgrade();
    shelly.display();
    return 0;
}