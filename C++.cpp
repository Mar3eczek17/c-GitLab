// SOLID
// I - Zasada segregacji interfejsów
// "Wiele dedykowanych interfejsów jest lepsze niż jeden ogólny." -> Wikipedia
 
#include <iostream>
#include <string>
 
 
class CzescIfu{
public:
    virtual ~CzescIfu() = default;
    virtual void czesc(const std::string imie) = 0;
};
 
class SpacerZpsemIfu{
public:
    virtual ~SpacerZpsemIfu() = default;
    virtual void spacerZpsem() = 0;
 
};
 
class BuziakIfu{
public:
    virtual ~BuziakIfu() = default;
    virtual void buziak() = 0;
};
 
 
class Ania : public CzescIfu, public SpacerZpsemIfu, public BuziakIfu
{
public:
    Ania()
    {
        std::cout << "Jestem Ania" << std::endl;
    }
 
    void czesc(const std::string imie) override {
        std::cout << "Czesc " << imie << std::endl; 
    }
 
    void buziak() override
    {
        std::cout << "Uwielbiam dostawac od Ciebie buziaki!" << std::endl;
    }
 
    void spacerZpsem() override {
        std::cout << "Chodzmy, Burek juz nie moze sie doczekac" << std::endl;
    }
};
 
 
 
class Piotrek{
public:
    Piotrek(Ania* ania_p):
    m_ania_p(ania_p),
    m_buziak_p(ania_p)
    {
        std::cout << "Jestem Piotrek" << std::endl;
    }
 
    void czescAnia()
    {
        m_ania_p->czesc("Piotrek");
    }
 
    void buziakDlaAni(){
        m_buziak_p->buziak();
    }
 
private:
    CzescIfu* m_ania_p;
    BuziakIfu* m_buziak_p;
 
};
 
class Adam{
public:
    Adam(Ania* ania_p):
    m_ania_p(ania_p),
    m_spacerZpsem_p(ania_p)
    {
        std::cout << "Jestem Adam" << std::endl;
    }
 
    void czescAnia()
    {
        m_ania_p->czesc("Adam");
    }
 
    void spacerZpsemAni(){
        m_spacerZpsem_p->spacerZpsem();
    }
 
private:
    CzescIfu* m_ania_p;
    SpacerZpsemIfu* m_spacerZpsem_p;
 
};
 
class Basia : public CzescIfu, public BuziakIfu
{
public:
    Basia()
    {
        std::cout << "Jestem Basia" << std::endl;
    }
 
    void czesc(const std::string imie) override {
        std::cout << "Basia: Czesc " << imie << std::endl; 
    }
 
    void buziak() override
    {
        std::cout << "Basia: Uwielbiam dostawac od Ciebie buziaki!" << std::endl;
    }
 
private:
 
};
 
 
 
int main()
{
    std::cout << "===> Interfejsy C++ <===" << std::endl << std::endl;
 
    Ania ania;
    //ania.czesc("Piotr");
    //ania.buziak();
    //ania.spacerZpsem();
 
    Piotrek piotrek(&ania);
    piotrek.czescAnia();
    piotrek.buziakDlaAni();
    piotrek.buziakDlaAni();
 
    Adam adam(&ania);
    adam.czescAnia();
    adam.spacerZpsemAni();
 
    Basia basia;
 
    BuziakIfu* buziaki[] = {&ania, &basia};
    for(BuziakIfu* buziak_p : buziaki)
    {
        buziak_p->buziak();
    }
 
    return 0;
}
