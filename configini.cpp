#include "configini.h"

ConfigIni* ConfigIni::configIni = NULL;

ConfigIni *ConfigIni::GetInstance()
{
    if(configIni == NULL)
    {
        configIni = new ConfigIni();
    }
    return configIni;
}

ConfigIni::ConfigIni(QObject *parent) : QObject(parent)
{
	QString configFile = QCoreApplication::applicationDirPath() + "/config.ini";
    if(QFile::exists(configFile))
    {
        QSettings* settings_ = new QSettings(QCoreApplication::applicationDirPath() + "/config.ini",QSettings::IniFormat);
        settings_->setIniCodec("UTF-8");

        settings_->beginGroup("MYSQL");
        ipMySql_= settings_->value("ip").toString();
        portMySql_ = settings_->value("port").toInt();
        dbName_ = settings_->value("dbname").toString();
        userNameMqSql_ = settings_->value("username").toString();;
        passWdMySql_ = settings_->value("password").toString();; 
        settings_->endGroup(); 

		settings_->beginGroup("ACTIVEMQ");
		activeMQ_= settings_->value("activeMQ").toString(); 
		settings_->endGroup(); 

		settings_->beginGroup("JAVAURL");
		javaUrl_= settings_->value("javaUrl").toString();  
		settings_->endGroup(); 

		settings_->beginGroup("DEVICEID");
		listDeviceId_ = settings_->value("id").toString().split(" "); 
		settings_->endGroup(); 

		settings_->beginGroup("DEPARTMENT");
		listDispDeptName_ = settings_->value("name").toString().split(" "); 
		settings_->endGroup(); 
    }
    else
    {
        SingletonLog->warn(configFile.toStdString() + " not exist");
    }
}


QString ConfigIni::getIpMySql() const
{
    return ipMySql_;
}

int ConfigIni::getPortMySql() const
{
    return portMySql_;
}

QString ConfigIni::getDbNameMySql() const
{
    return dbName_;
}

QString ConfigIni::getUserNameMySql() const
{
    return userNameMqSql_;
}

QString ConfigIni::getPassWdMySql() const
{
    return passWdMySql_;
}


QString ConfigIni::getActiveMQ() const
{
	return activeMQ_; 
}

QString ConfigIni::getJavaUrl() const
{ 
	return javaUrl_;
}
 
QStringList  ConfigIni::getDeviceId() const
{
	return listDeviceId_;
}
 
QStringList  ConfigIni::getDispDeptName() const
{
	return listDispDeptName_;
}



