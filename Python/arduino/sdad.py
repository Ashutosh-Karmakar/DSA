GET pickupLocation
GET dropLocation
IF(pickupLocation and dropLocation is not empty)THEN
   Number = SEARCH in CAB DATABASE for number of vehicles available in pickupLocation
   IF (NUMBER is NULL) THEN
      Message: There are no cab available at present time please wat for some time
   ELSE
      Pick  a driver from CAB DATABASE and allocate it with the customer
      Return the driver name , vehicle details and OTP to user
   END IF
END IF
