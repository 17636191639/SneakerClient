#include "evaluationinfo.h"

EvaluationInfo::EvaluationInfo()
{

}

EvaluationInfo::EvaluationInfo(const QString &id, const QString &shoesID, const QString &buyerID, const QString &photoID, const QString &grade, const QString &content,
                const QString &date)
{
    m_id = id;
    m_shoesID = shoesID;
    m_buyerID = buyerID;
    m_photoID = photoID;
    m_grade = grade;
    m_content = content;
//    m_photoCount = photoCount;
//    m_photoPath = photoPath;
    m_date = date;
}

void EvaluationInfo::setID(const QString &id)
{
    m_id = id;

}
void EvaluationInfo::setShoesID(const QString &shoesID)
{
    m_shoesID = shoesID;

}
void EvaluationInfo::setBuyerID(const QString &buyerID)
{
    m_buyerID = buyerID;
}
void EvaluationInfo::setPhotoID(const QString &photoID)
{
    m_photoID = photoID;
}
void EvaluationInfo::setGrade(const QString &grade)
{
    m_grade = grade;

}
void EvaluationInfo::setContent(const QString &content)
{
    m_content = content;

}
//void EvaluationInfo::setPhotoCount(const QString &photoCount)
//{
//    m_photoCount = photoCount;

//}
//void EvaluationInfo::setPhotoPath(const QString &photoPath)
//{
//    m_photoPath = photoPath;

//}
void EvaluationInfo::setDate(const QString &date)
{
    m_date = date;
}

const QString &EvaluationInfo::getID(void) const
{
    return m_id;
}
const QString &EvaluationInfo::getShoesID(void) const
{
    return m_shoesID;
}
const QString &EvaluationInfo::getPhotoID(void) const
{
    return m_photoID;
}
const QString &EvaluationInfo::getBuyerID(void) const
{
    return m_buyerID;
}
const QString &EvaluationInfo::getGrade(void) const
{
    return m_grade;
}
const QString &EvaluationInfo::getContent(void) const
{
    return m_content;
}
//const QString &EvaluationInfo::getPhotoCount(void) const
//{
//    return m_photoCount;
//}
//const QString &EvaluationInfo::getPhotoPath(void) const
//{
//    return m_photoPath;
//}
const QString &EvaluationInfo::getDate(void) const
{
    return m_date;
}
