#ifndef AWEAPON_H
#define AWEAPON_H

class AWeapon {

	private:

	public:
		AWeapon(std::string const & name, int apcost, int damage);
	  [...] ~AWeapon();
		std::string [...] getName() const;
		int getAPCost() const;
		int getDamage() const;
	  [...] void attack() const = 0;
};

#endif
