/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:41:35 by phijano-          #+#    #+#             */
/*   Updated: 2023/06/29 13:21:08 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void leaks(void)
{
	system("leaks FF7");
}

int main()
{
	std::cout << "*************BASIC TEST**********************" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	
	AMateria* tmp;	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	std::cout << "*************DEEP COPY TEST**********************" << std::endl;

	MateriaSource *Mysource = new MateriaSource();
	Mysource->learnMateria(new Ice());
	Mysource->learnMateria(new Cure());

	MateriaSource *deepCopyConstructorMS = new MateriaSource(*Mysource);
	MateriaSource *deepAssignationMS = new MateriaSource();
	deepAssignationMS->learnMateria(new Ice());// test for leaks in assigment
	*deepAssignationMS = *Mysource;

	delete Mysource;

	Character* cloud = new Character("cloud");

	tmp = deepCopyConstructorMS->createMateria("ice");
	cloud->equip(tmp);
	tmp = deepAssignationMS->createMateria("cure");
	cloud->equip(tmp);
	
	delete deepCopyConstructorMS;
	delete deepAssignationMS;

	Character* deepCopyConstructorC = new Character(*cloud);
	Character* deepAssignationC = new Character();
	deepAssignationC->equip(new Cure());// test for leaks in assigment
	*deepAssignationC = *cloud;
	
	delete cloud;
		
	ICharacter*  shinraSoldier= new Character("shinra soldier");;

	deepCopyConstructorC->use(0, *shinraSoldier);
	deepAssignationC->use(1, *shinraSoldier);

	delete deepCopyConstructorC;
	delete deepAssignationC;
	delete shinraSoldier;

	atexit(leaks);

	return 0;
}
