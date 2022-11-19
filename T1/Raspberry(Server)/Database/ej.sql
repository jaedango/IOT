-- MySQL Script generated by MySQL Workbench
-- Wed Oct 19 18:21:44 2022
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`configuration`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`configuration` (
  `Id_device` INT GENERATED ALWAYS AS () VIRTUAL,
  `Status_conf` INT GENERATED ALWAYS AS () VIRTUAL,
  `Protocol_conf` INT GENERATED ALWAYS AS () VIRTUAL,
  `Acc_sampling` INT NULL,
  `Acc_sensibility` INT NULL,
  `Gyro_sensibility` INT NULL,
  `BME688_sampling` INT NULL,
  `Discontinuos_time` INT NULL,
  `TCP_PORT` INT NULL,
  `UDP_port` INT NULL,
  `Host_ip_addr` INT NULL,
  `Ssid` VARCHAR(45) NULL,
  `Pass` VARCHAR(45) NULL,
  PRIMARY KEY (`Id_device`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`timestamps`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`timestamps` (
  `create_time` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP,
  `update_time` TIMESTAMP NULL);


-- -----------------------------------------------------
-- Table `mydb`.`Log`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Log` (
  `Id_device` INT GENERATED ALWAYS AS () VIRTUAL,
  `Status_report` INT GENERATED ALWAYS AS () VIRTUAL,
  `Protocol_report` INT GENERATED ALWAYS AS () VIRTUAL,
  `Battery Level` INT NULL,
  `Conf_peripheral` INT NULL,
  `Time_client` DATETIME GENERATED ALWAYS AS () VIRTUAL,
  `Time_server` TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP,
  `configuration_Id_device` INT NOT NULL,
  PRIMARY KEY (`Id_device`),
  INDEX `fk_Log_configuration1_idx` (`configuration_Id_device` ASC) VISIBLE,
  CONSTRAINT `fk_Log_configuration1`
    FOREIGN KEY (`configuration_Id_device`)
    REFERENCES `mydb`.`configuration` (`Id_device`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Data_1`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Data_1` (
  `Id_device` INT NOT NULL,
  `Temperature` INT NULL,
  `Press` INT NULL,
  `Hum` INT NULL,
  `Co` FLOAT NULL,
  `RMS` FLOAT NULL,
  `Amp_x` FLOAT NULL,
  `Freq_x` FLOAT NULL,
  `Amp_y` FLOAT NULL,
  `Freq_y` FLOAT NULL,
  `Amp_z` FLOAT NULL,
  `Freq_z` FLOAT NULL,
  `Time_client` DATETIME GENERATED ALWAYS AS () VIRTUAL,
  `Log_Id_device` INT NOT NULL,
  PRIMARY KEY (`Id_device`),
  INDEX `fk_Data_1_Log_idx` (`Log_Id_device` ASC) VISIBLE,
  CONSTRAINT `fk_Data_1_Log`
    FOREIGN KEY (`Log_Id_device`)
    REFERENCES `mydb`.`Log` (`Id_device`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Data_2`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Data_2` (
  `Id_device` INT NOT NULL,
  `Racc_x` FLOAT NULL,
  `Racc_y` FLOAT NULL,
  `Racc_z` FLOAT NULL,
  `Rgyr_x` FLOAT NULL,
  `Rgyr_y` FLOAT NULL,
  `Rgyr_z` FLOAT NULL,
  `Time_client` DATETIME GENERATED ALWAYS AS () VIRTUAL,
  `Log_Id_device` INT NOT NULL,
  PRIMARY KEY (`Id_device`),
  INDEX `fk_Data_2_Log1_idx` (`Log_Id_device` ASC) VISIBLE,
  CONSTRAINT `fk_Data_2_Log1`
    FOREIGN KEY (`Log_Id_device`)
    REFERENCES `mydb`.`Log` (`Id_device`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
