#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

using namespace std;

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << getName() << ": My job here is done!" << std::endl;
}
const std::string &Warlock::getName() const
{
    return (this->_name);
}

const std::string &Warlock::getTitle() const
{
    return (this->_title);
}

void Warlock::setTitle(const std::string &title)
{
    this->_title = title;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell != nullptr)
    {
        if (_SpellBook.find(spell->getName()) == _SpellBook.end())
            _SpellBook[spell->getName()] = spell->clone();
    }
}

void Warlock::forgetSpell(std::string spellName)
{
    map<string, ASpell *>::iterator it;

    if (_SpellBook.find(spellName) != _SpellBook.end())
    {
        delete it->second; // libero la memoria
        _SpellBook.erase(spellName); // borro del map esa entrada
    }
}

void Warlock::launchSpell(std::string spellName, const ATarget &src)
{
    map<string, ASpell *>::iterator it;

    if (_SpellBook.find(spellName) != _SpellBook.end())
        it->second->launch(src);
}
