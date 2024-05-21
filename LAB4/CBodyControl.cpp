#include "stdafx.h"
#include "CBodyControl.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "CSphere.h"
#include "CCompound.h"

const double WATER_DENSITY = 1000.0;

enum BodieType
{
    wrongType = -1,
    sphere = 0,
    parallelepiped = 1,
    cone = 2,
    cylinder = 3,
    compound = 4
};

CBodyControl::CBodyControl(vector<shared_ptr<CBody>>& bodies
    , istream& input
    , ostream& output)
    : mbodies(bodies)
    , minp(input)
    , mout(output)
{
}

void CBodyControl::ReadBodies()
{
    char choise = 'y';
    while (!minp.eof())
    {
        mbodies.push_back(move(ReadSimpleBody()));
        mout << "Continue? ('y' for continue): ";
        minp >> choise;
        if (choise != 'y')
        {
            break;
        }
    };
}

void CBodyControl::WriteBodies()
{
    mout << "Information about bodies:" << endl;
    for (const auto& body : mbodies)
    {
        if (body != nullptr)
        {
            mout << body->ToString() << endl;
        }
    }
}

vector<shared_ptr<CBody>> CBodyControl::ReadCompoundBody() const
{
    mout << "You started entering compound body\n";
    char choise = 'y';
    std::vector<shared_ptr<CBody>> children;
    while (!minp.eof())
    {
        children.push_back(std::move(ReadSimpleBody()));
        mout << "Continue? ('y' for continue): ";
        minp >> choise;
        if (choise != 'y')
        {
            mout << "You ended entering last compound body\n";
            break;
        }
    };
    return children;
}

shared_ptr<CBody> CBodyControl::ReadSimpleBody() const
{
    string type;
    mout << "Enter the type of body (sphere, parallelepiped, cone, cylinder): ";
    minp >> type;
    map<string, BodieType> types{ {"sphere", BodieType::sphere }, {"parallelepiped", BodieType::parallelepiped}, {"cone", BodieType::cone},
                                            {"cylinder", BodieType::cylinder}, {"compound", BodieType::compound} };
    BodieType bodieType = BodieType::wrongType;
    if (types.count(type) > 0)
    {
        bodieType = types[type];
    }
    switch (bodieType)
    {
        double density, radius, length, width, height;
    case BodieType::sphere:
        mout << "Enter the density: ";
        minp >> density;
        mout << "Enter the radius of the sphere: ";
        minp >> radius;
        return make_shared<CSphere>(density, radius);
    case BodieType::parallelepiped:
        mout << "Enter the density: ";
        minp >> density;
        mout << "Enter the length, width, and height of the parallelepiped: ";
        minp >> length >> width >> height;
        return make_shared<CParallelepiped>(density, length, width, height);
    case BodieType::cone:
        mout << "Enter the density: ";
        minp >> density;
        mout << "Enter the radius and height of the cone: ";
        minp >> radius >> height;
        return make_shared<CCone>(density, radius, height);
    case BodieType::cylinder:
        mout << "Enter the density: ";
        minp >> density;
        mout << "Enter the radius and height of the cone: ";
        minp >> radius >> height;
        return make_shared<CCylinder>(density, radius, height);
    case BodieType::compound:
        return make_shared<CCompound>(ReadCompoundBody());
    default:
        mout << "Invalid body type." << endl;
        return nullptr;
    }
}

void CBodyControl::WriteHaviestBody()
{
    std::shared_ptr<CBody> heaviestBody = FindHeaviestBody();

    if (heaviestBody != nullptr)
    {
        mout << "Heaviest body: " << heaviestBody->ToString() << endl;
    }
    else {
        mout << "No bodies found." << endl;
    }
}

shared_ptr<CBody> CBodyControl::FindHeaviestBody() const
{
    if (mbodies.empty()) {
        return nullptr;
    }
    auto compareMass = [](const shared_ptr<CBody>& body1, const shared_ptr<CBody>& body2)
    {
        return body1->GetMass() < body2->GetMass();
    };

    auto heaviestBodyIterator = max_element(mbodies.begin(), mbodies.end(), compareMass);

    return *heaviestBodyIterator;
}

void CBodyControl::WriteLightestBodyInWater() const
{
    shared_ptr<CBody> lightestInWaterBody = FindLightestInWaterBody();

    if (lightestInWaterBody != nullptr)
    {
        mout << "Lightest body in water: " << lightestInWaterBody->ToString() << endl;
    }
    else {
        mout << "No bodies found." << endl;
    }
}

shared_ptr<CBody> CBodyControl::FindLightestInWaterBody() const
{
    if (mbodies.empty()) {
        return nullptr;
    }

    auto compareMassInWater = [](const shared_ptr<CBody>& body1, const shared_ptr<CBody>& body2)
        {
            return ((body1->GetMass() - body1->GetVolume() * WATER_DENSITY)
                < (body2->GetMass() - body2->GetVolume() * WATER_DENSITY));
        };

    auto lighestBodyIterator = min_element(mbodies.begin(), mbodies.end(), compareMassInWater);

    return *lighestBodyIterator;
}