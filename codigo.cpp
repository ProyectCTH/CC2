#include <iostream>
class Subject
{
public:
    virtual void Request() const = 0;
};

class RealSubject : public Subject
{
public:
    void Request() const override
    {
        std::cout << "RealSubject: Solicitud de manejo.\n";
    }
};

class Proxy : public Subject
{
private:
    RealSubject *real_subject_;

    bool CheckAccess() const
    {
        std::cout << "Proxy: Comprobar el acceso antes de activar una solicitud real.\n";
        return true;
    }
    void LogAccess() const
    {
        std::cout << "Proxy: Registrar la hora de la solicitud.\n";
    }

public:
    Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject))
    {
    }

    ~Proxy()
    {
        delete real_subject_;
    }

    void Request() const override
    {
        if (this->CheckAccess())
        {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};

void ClientCode(const Subject &subject)
{
    // ...
    subject.Request();
    // ...
}

int main()
{
    std::cout << "Client: Ejecutando el codigo del cliente con un asunto real :\n";
    RealSubject *real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Client: Ejecutar el mismo codigo de cliente con un proxy:\n";
    Proxy *proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}
