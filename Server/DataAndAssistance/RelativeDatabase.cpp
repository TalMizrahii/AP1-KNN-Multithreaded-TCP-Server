#include "RelativeDatabase.h"

#include <utility>


/**
 * A default constructor.
 */
RelativeDatabase::RelativeDatabase() = default;

/**
 * A default destructor.
 */
RelativeDatabase::~RelativeDatabase() = default;

/**
 * A setter for an unclassified Relative vector.
 * @param unclassifiedRelativesVec The unclassified Relative vector.
 */
void RelativeDatabase::setUnclassifiedRelatives(vector<RelativeVector *> unclassifiedRelativesVec) {
    this->unclassifiedRelatives = std::move(unclassifiedRelativesVec);
}

/**
 * A setter for an classified Relative vector.
 * @param classifiedRelativesVec The classified Relative vector.
 */
void RelativeDatabase::setClassifiedRelatives(vector<ClassifiedRelativeVector *> classifiedRelativesVec) {
    this->classifiedRelatives = std::move(classifiedRelativesVec);
}

/**
 * A getter for the unclassified Relative vector.
 * @return The unclassified Relative vector.
 */
vector<RelativeVector *> RelativeDatabase::getUnclassifiedRelatives() {
    return this->unclassifiedRelatives;
}


/**
 * A getter for the classified Relative vector.
 * @return The classified Relative vector.
 */
vector<ClassifiedRelativeVector *> RelativeDatabase::getClassifiedRelatives() {
    return this->classifiedRelatives;
}

/**
 * A getter to implement singleton design pattern.
 * @return The instance of the class.
 */
 RelativeDatabase *RelativeDatabase::getInstance() {
    if(!relativeDatabasePtr){
        relativeDatabasePtr = new RelativeDatabase();
    }
     return relativeDatabasePtr;
}

/**
 *  Setter for k element member.
 * @param k element.
 */
void RelativeDatabase::setKElement(int k) {
    this->kElement = k;
}


/**
 *  Setter for distance metric member.
 * @param metric - The distance metric.
 */
void RelativeDatabase::setMetric(string metric) {
    this->distanceMetric = std::move(metric);
}

/**
 *  Getter for k element member.
 * @return k element member.
 */
int RelativeDatabase::getKElement() {
    return this->kElement;
}

/**
 *  Getter for distance metric member.
 * @return distance metric member.
 */
string RelativeDatabase::getMetric() {
    return this->distanceMetric;
}
