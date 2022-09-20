//
//  Network.hpp
//  a1
//
//  Created by Maximilian Wernz on 20.09.22.
//

#ifndef ElectricalNetwork_h
#define ElectricalNetwork_h

class Network {
public:
    virtual double ohm() const = 0;
    virtual ~Network() {}
};

class Resistor : public Network {
    int m_val;
public:
    Resistor(int val=0) : m_val(val) {}
    Resistor(const Resistor& other) : m_val(other.m_val) {}
    double ohm() const override { return m_val; }
    void setOhm(double val);
};

class Serial : public Network {
    Network* m_a;
    Network* m_b;
public:
    Serial(Network* a, Network* b) : m_a(a), m_b(b) {}
    double ohm() const override { return m_a->ohm() + m_b->ohm(); }
};

class Parallel : public Network {
    Network* m_a;
    Network* m_b;
public:
    Parallel(Network* a, Network* b) : m_a(a), m_b(b) {}
    double ohm() const override { return (m_a->ohm() * m_b->ohm()) / (m_a->ohm() + m_b->ohm()); }
};

#endif /* Network_hpp */
