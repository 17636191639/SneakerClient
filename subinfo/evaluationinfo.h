#ifndef EVALUATIONINFO_H
#define EVALUATIONINFO_H
#include <QString>

class EvaluationInfo
{
public:
    EvaluationInfo();
    EvaluationInfo(const QString &id, const QString &shoesID, const QString &photoID, const QString &buyerID,
                   const QString &grade, const QString &content, const QString &date);

    //const QString &photoCount, const QString &photoPath,
    void setID(const QString &id);
    void setShoesID(const QString &shoesID);
    void setBuyerID(const QString &buyerID);
    void setPhotoID(const QString &photoID);
    void setGrade(const QString &grade);
    void setContent(const QString &content);
    //void setPhotoCount(const QString &photoCount);
    //void setPhotoPath(const QString &photoPath);
    void setDate(const QString &date);

    const QString &getID(void) const;
    const QString &getShoesID(void) const;
    const QString &getBuyerID(void) const;
    const QString &getPhotoID(void) const;
    const QString &getGrade(void) const;
    const QString &getContent(void) const;
    //const QString &getPhotoCount(void) const;
    //const QString &getPhotoPath(void) const;
    const QString &getDate(void) const;

private:
    QString m_id;
    QString m_shoesID;
    QString m_buyerID;
    QString m_photoID;
    QString m_grade;
    QString m_content;
    //QString m_photoCount;
    //QString m_photoPath;
    QString m_date;
};

typedef QList<EvaluationInfo> EvaluationInfoList;
#endif // EVALUATIONINFO_H
