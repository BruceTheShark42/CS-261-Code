#include "productiondb.h"

productiondb::productiondb(const productiondb& db)
	: entries(db.entries), years(db.years), stations(db.stations), resources(db.resources), months(db.months) {}

