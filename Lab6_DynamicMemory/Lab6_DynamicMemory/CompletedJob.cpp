#include "CompletedJob.h"

static const bool DEBUG_MODE = false;

/*
* Create a new CompletedJob
*/
CompletedJob::CompletedJob() {
	setClientName("");
	setRoomsPainted(0);
	setLaborCharges(0);
	setNumberOfPaintCans(0);
	setProductCharges(0);
	setMileage(0);
	setTravelCharges(0);

	invoiceNumber = 1 + (rand() % 1000);
}

/*
* Destroy a CompletedJob
*/
CompletedJob::~CompletedJob() {
}

/*
* Update the client name
* Params:
* name - The new name of the client
*/
void CompletedJob::setClientName(std::string name) {
	clientName = name;
}

/*
* Get the client name
* Return:
* The name of the client
*/
std::string CompletedJob::getClientName() {
	return clientName;
}

/*
* Get the invoice number of the job
*/
int CompletedJob::getInvoiceNumber() {
	return invoiceNumber;
}

/*
* Update the number of rooms painted
* Params:
* rooms - The new number of rooms
* Return:
* Whether the number of rooms was updated successfully
*/
bool CompletedJob::setRoomsPainted(int rooms) {
	if (rooms < 0) {
		return false;
	}
	roomsPainted = rooms;
	return true;
}

/*
* Get the number of rooms painted
* Return:
* The number of rooms painted
*/
int CompletedJob::getRoomsPainted() {
	return roomsPainted;
}

/*
* Update the labor charges
* Params:
* charges - The new labor charges
* Return:
* Whether the labor charges were updated successfully
*/
bool CompletedJob::setLaborCharges(double charges) {
	if (charges < 0) {
		return false;
	}
	laborCharges = charges;
	return true;
}

/*
* Get the labor charges
* Return:
* The labor charges
*/
double CompletedJob::getLaborCharges() {
	return laborCharges;
}

/*
* Update the number of paint cans used
* Params:
* numberOfCans - The new number of cans used
* Return:
* Whether the number of paint cans was updated successfully
*/
bool CompletedJob::setNumberOfPaintCans(int numberOfCans) {
	if (numberOfCans < 0) {
		return false;
	}
	numberOfPaintCans = numberOfCans;
	return true;
}

/*
* Get the number of paint cans used
* Return:
* The number of paint cans used
*/
int CompletedJob::getNumberOfPaintCans() {
	return numberOfPaintCans;
}

/*
* Update the product charges
* Params:
* charges - The new product charges
* Return:
* Whether the product charges was updated successfully
*/
bool CompletedJob::setProductCharges(double charges) {
	if (charges < 0) {
		return false;
	}
	productCharges = charges;
	return true;
}

/*
* Get the product charges for the job
* Return:
* The product charges
*/
double CompletedJob::getProductCharges() {
	return productCharges;
}

/*
* Update the mileage
* Params:
* rooms - The new mileage
* Return:
* Whether the mileage was updated successfully
*/
bool CompletedJob::setMileage(double miles) {
	if (miles < 0) {
		return false;
	}
	mileage = miles;
	return true;
}

/*
* Get the mileage to the job
* Return:
* The mileage
*/
double CompletedJob::getMileage() {
	return mileage;
}

/*
* Update the travel charges
* Params:
* rooms - The new travel charges
* Return:
* Whether the travel charges were updated successfully
*/
bool CompletedJob::setTravelCharges(double charges) {
	if (charges < 0) {
		return false;
	}
	travelCharges = charges;
	return true;
}

/*
* Get the travel charges]
* Return: The travel charges
*/
double CompletedJob::getTravelCharges() {
	return travelCharges;
}