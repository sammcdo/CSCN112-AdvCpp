#pragma once

#include <string>

class CompletedJob {
public:
	/*
	* Create a new CompletedJob
	*/
	CompletedJob();
	/*
	* Destroy a CompletedJob
	*/
	~CompletedJob();

	/*
	* Update the client name
	* Params:
	* name - The new name of the client
	*/
	void setClientName(std::string name);

	/*
	* Get the client name
	* Return:
	* The name of the client
	*/
	std::string getClientName();

	/*
	* Get the invoice number of the job
	*/
	int getInvoiceNumber();

	/*
	* Update the number of rooms painted
	* Params:
	* rooms - The new number of rooms
	* Return:
	* Whether the number of rooms was updated successfully
	*/
	bool setRoomsPainted(int rooms);

	/*
	* Get the number of rooms painted
	* Return:
	* The number of rooms painted
	*/
	int getRoomsPainted();

	/*
	* Update the labor charges
	* Params:
	* charges - The new labor charges
	* Return:
	* Whether the labor charges were updated successfully
	*/
	bool setLaborCharges(double charges);

	/*
	* Get the labor charges
	* Return:
	* The labor charges
	*/
	double getLaborCharges();


	/*
	* Update the number of paint cans used
	* Params:
	* numberOfCans - The new number of cans used
	* Return:
	* Whether the number of paint cans was updated successfully
	*/
	bool setNumberOfPaintCans(int numberOfCans);

	/*
	* Get the number of paint cans used
	* Return:
	* The number of paint cans used
	*/
	int getNumberOfPaintCans();

	/*
	* Update the product charges
	* Params:
	* charges - The new product charges
	* Return:
	* Whether the product charges was updated successfully
	*/
	bool setProductCharges(double charges);

	/*
	* Get the product charges for the job
	* Return:
	* The product charges
	*/
	double getProductCharges();

	/*
	* Update the mileage
	* Params:
	* rooms - The new mileage
	* Return:
	* Whether the mileage was updated successfully
	*/

	bool setMileage(double mileage);

	/*
	* Get the mileage to the job
	* Return:
	* The mileage
	*/
	double getMileage();

	/*
	* Update the travel charges
	* Params:
	* rooms - The new travel charges
	* Return:
	* Whether the travel charges were updated successfully
	*/
	bool setTravelCharges(double charges);

	/*
	* Get the travel charges]
	* Return: The travel charges
	*/
	double getTravelCharges();
	
private:
	std::string clientName;
	int invoiceNumber;
	int roomsPainted;
	double laborCharges;
	int numberOfPaintCans;
	double productCharges;
	double mileage;
	double travelCharges;
};