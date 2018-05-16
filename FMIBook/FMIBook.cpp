#include "FMIBook.h"

FMIBook::FMIBook(Command* command) {
	switch (command->getCommandType()) {
	case INVALID_COMMAND:	std::cerr << "Invalid command." << std::endl; break;
	case QUIT:				throw std::logic_error("Exit"); break; //????????
	case ADD_MODERATOR:		addModerator(command); break;
	case ADD_USER:			addUser(command); break;
	case BLOCK_USER:		blockUser(command); break;
	case UNBLOCK_USER:		unblockUser(command); break;
	case INFO:				printInfo(); break;
	case REMOVE_USER:		removeUser(command); break;
	case RENAME:			renameUser(command); break;
	case POST_IMAGE:		createPost(command); break;
	case POST_URL:			createPost(command); break;
	case POST_TEXT:			createPost(command); break;
	case VIEW_POST_LIST:    printPostList(); break;
	case REMOVE_POST:		removePost(command); break;
	}

}

void FMIBook::createAdministrator() {
	User administrator("Admin", 20, ADMIN_PERMISSIONS);
	FMIBook::user_list.push_back(administrator);
}

FMIBook::~FMIBook() {

}

size_t FMIBook::findUserPos(const char* userName) {
	if (FMIBook::userExists(userName)) {
		size_t numberOfUsers = FMIBook::user_list.size();

		for (int i = 0; i < numberOfUsers; i++) {
			if (FMIBook::user_list[i].compareWith(userName)) {
				return i;
			}
		}
	}
	else {
		throw std::logic_error("No such user in database");
	}
}

void FMIBook::printInfo() {
	size_t numberOfUsers = FMIBook::user_list.size();

	for (int i = 0; i < numberOfUsers; i++) {
		FMIBook::user_list[i].printInformationCompact();
	}

	if (numberOfUsers > 1) {
		std::cout << "Oldest user: " << FMIBook::user_list[getOldestUserIndex()].getNickname();
		std::cout << ", " << FMIBook::user_list[getOldestUserIndex()].getAge() << std::endl;
		std::cout << "Youngest user: " << FMIBook::user_list[getYoungestUserIndex()].getNickname();
		std::cout << ", " << FMIBook::user_list[getYoungestUserIndex()].getAge() << std::endl;;
	}

	std::cout << "Blocked users: ";
	listBlockedUsers();
	printMostLeastPostsUsers();
	std::cout << std::endl;
}

void FMIBook::addModerator(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());

	if (userExists(command->getSubject())) {
		throw std::logic_error("Subject already exists in database");
	}
	if (FMIBook::user_list.at(actor_pos).getPermissions()->canAddModerator()) {
		size_t subjectAge = command->getSubjectAge();
		User newUser(command->getSubject(), subjectAge, MOD_PERMISSIONS);
		FMIBook::user_list.push_back(newUser);
		std::cout << "Moderator added to database\n";
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::addUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());

	if (userExists(command->getSubject())) {
		throw std::logic_error("Subject already exists in database");
	}

	if (FMIBook::user_list.at(actor_pos).getPermissions()->canAddUser()) {
		size_t subjectAge = command->getSubjectAge();
		User newUser(command->getSubject(), subjectAge, USER_PERMISSIONS);
		FMIBook::user_list.push_back(newUser);
		std::cout << "User added to database\n";
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::blockUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());
	size_t subject_pos = findUserPos(command->getSubject());

	if (FMIBook::user_list.at(actor_pos).getPermissions()->canBlockUser()) {
		if (FMIBook::user_list.at(actor_pos).getPermissions()->canBlockUser()) {
			FMIBook::user_list.at(subject_pos).getPermissions()->blockPosting();
		}
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::unblockUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());
	size_t subject_pos = findUserPos(command->getSubject());

	if (FMIBook::user_list.at(actor_pos).getPermissions()->canUnblockUser()) {
		if (FMIBook::user_list.at(actor_pos).getPermissions()->canUnblockUser()) {
			FMIBook::user_list.at(subject_pos).getPermissions()->unblockPosting();
		}
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

bool FMIBook::userExists(const char* userName) {
	size_t numberOfUsers = FMIBook::user_list.size();

	bool doesExist = false;
	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list[i].compareWith(userName)) {
			doesExist = true;
			break;
		}
	}

	return doesExist;
}

void FMIBook::removeUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());
	size_t subject_pos = findUserPos(command->getSubject());

	if (FMIBook::user_list[actor_pos].getPermissions()->canRemoveUser()) {
		FMIBook::user_list.erase(FMIBook::user_list.begin() + subject_pos);
		std::cout << "User has been removed";
	}
	else {
		throw std::logic_error("Actor does not have needed permissions");
	}
}

void FMIBook::renameUser(Command* command) {
	size_t actor_pos = findUserPos(command->getActor());

	char* oldName = FMIBook::user_list.at(actor_pos).getNickname();
	char* newName = command->getSubject();

	if (userExists(newName)) {
		throw std::logic_error("New name already exists in database");
	}

	for (int i = 0; newName[i] != '\0'; i++) {
		oldName[i] = newName[i];
		if (newName[i + 1] == '\0') {
			oldName[i + 1] = '\0';
		}
	}

	std::cout << "User has been renamed" << std::endl;
}

size_t FMIBook::getOldestUserIndex() {
	size_t numberOfUsers = FMIBook::user_list.size();
	size_t currentOldestIndex = 0;

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getAge() > FMIBook::user_list.at(currentOldestIndex).getAge()) {
			currentOldestIndex = i;
		}
	}

	return currentOldestIndex;
}

size_t FMIBook::getYoungestUserIndex() {
	size_t numberOfUsers = FMIBook::user_list.size();
	size_t currentOldestIndex = 0;

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getAge() < FMIBook::user_list.at(currentOldestIndex).getAge()) {
			currentOldestIndex = i;
		}
	}

	return currentOldestIndex;
}

size_t FMIBook::getBlockedUsersCount() {
	size_t numberOfUsers = FMIBook::user_list.size();
	size_t blockedUsersCount = 0;

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getPermissions()->isBlockedFromPosting()) {
			blockedUsersCount++;
		}
	}

	return blockedUsersCount;
}

void FMIBook::listBlockedUsers() {
	size_t blockedUsersCount = getBlockedUsersCount();

	if (blockedUsersCount == 0) {
		std::cout << "N/A" << std::endl;
	}
	else if (blockedUsersCount > 0) {
		int* blockedUsersIndexes = new int[blockedUsersCount];
		getBlockedUsersIndexes(blockedUsersIndexes);

		for (int i = 0; i < blockedUsersCount; i++) {
			std::cout << FMIBook::user_list.at(blockedUsersIndexes[i]).getNickname();
			if (i + 1 != blockedUsersCount) {
				std::cout << ", ";
			}
		}

		std::cout << std::endl;
		delete[] blockedUsersIndexes;
	}
}

void FMIBook::getBlockedUsersIndexes(int* blockedUsersIndexesArray) {
	size_t currentArrayIndex = 0;
	size_t numberOfUsers = FMIBook::user_list.size();

	for (int i = 0; i < numberOfUsers; i++) {
		if (FMIBook::user_list.at(i).getPermissions()->isBlockedFromPosting()) {
			blockedUsersIndexesArray[currentArrayIndex] = i;
			currentArrayIndex++;
		}
	}
}

void FMIBook::printPostList() {
	size_t numberOfPosts = FMIBook::post_list.size();

	if (numberOfPosts == 0) {
		std::cout << "No posts in database" << std::endl;
	}

	for (int postIndex = 0; postIndex < numberOfPosts; postIndex++) {
		std::cout << postIndex + 1 << ". ";
		FMIBook::post_list.at(postIndex).printInformationCompact();
		std::cout << std::endl;
	}
}

void FMIBook::createPost(Command* command) {
	try {
		FMIBook::post_list.push_back(Post(command));
		switch (command->getCommandType()) {
		case POST_IMAGE: std::cout << "Image posted\n"; break;
		case POST_URL: std::cout << "Url posted\n"; break;
		case POST_TEXT: std::cout << "Text posted\n"; break;
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

size_t FMIBook::getLeastPostsUserPos() {
	size_t leastPostsUserPos = 0;
	size_t usersCount = FMIBook::user_list.size();

	for (int currentUserPos = 0; currentUserPos < usersCount; currentUserPos++) {
		if (FMIBook::user_list.at(currentUserPos).getPostsCount() < FMIBook::user_list.at(leastPostsUserPos).getPostsCount()) {
			leastPostsUserPos = currentUserPos;
		}
	}

	return leastPostsUserPos;
}

size_t FMIBook::getMostPostsUserPos() {
	size_t mostsPostsUserPos = 0;
	size_t usersCount = FMIBook::user_list.size();

	for (int currentUserPos = 0; currentUserPos < usersCount; currentUserPos++) {
		if (FMIBook::user_list.at(currentUserPos).getPostsCount() > FMIBook::user_list.at(mostsPostsUserPos).getPostsCount()) {
			mostsPostsUserPos = currentUserPos;
		}
	}
	return mostsPostsUserPos;
}

void FMIBook::printMostLeastPostsUsers() {
	size_t mostPostsUserPos = getMostPostsUserPos();
	size_t leastPostsUserPos = getLeastPostsUserPos();

	if (mostPostsUserPos == leastPostsUserPos) {
		return;
	}

	if (FMIBook::user_list.at(leastPostsUserPos).getPostsCount() == 0) {
		return;
	}


	std::cout << "Most posts: " << FMIBook::user_list.at(mostPostsUserPos).getNickname() << std::endl;
	std::cout << "Least posts: " << FMIBook::user_list.at(leastPostsUserPos).getNickname() << std::endl;
	std::cout << std::endl;
}

void FMIBook::removePost(Command* command) {
	size_t postNumber = command->getPostId() - 1;
	size_t postCreator = findPosterPos(postNumber);
	size_t postRemover = findUserPos(command->getActor());

	if (FMIBook::user_list.at(postRemover).getPermissions()->canRemoveAnyPost()) {
		FMIBook::post_list.erase(FMIBook::post_list.begin() + postNumber);
		std::cout << "Post removed";
		return;
	}


	if ((postCreator == postRemover) && FMIBook::user_list.at(postRemover).getPermissions()->canRemoveOwnPost()) {
		FMIBook::post_list.erase(FMIBook::post_list.begin() + postNumber);
		std::cout << "Post removed";
		return;
	}

	if ((postCreator != postRemover) && !FMIBook::user_list.at(postRemover).getPermissions()->canRemoveAnyPost()) {
		throw std::logic_error("Actor does not have needed permissions");
	}

}

size_t FMIBook::findPosterPos(size_t postId) {
	size_t posterPos = 0;
	size_t usersCount = FMIBook::user_list.size();

	for (int currentPos = 0; currentPos < usersCount; currentPos++) {
		if (FMIBook::post_list.at(postId).isPoster(FMIBook::user_list.at(currentPos).getNickname())) {
			posterPos = currentPos;
		}
	}

	return posterPos;
}