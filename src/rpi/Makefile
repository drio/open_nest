PI_SSH="pi@192.168.1.232"
PI_DIR="/home/pi/open_nest"

.PHONY: deploy

deploy:
	# Create project dir in RPI
	ssh $(PI_SSH) 'mkdir -p $(PI_DIR)'

	# Transfer the latest version of the communicator
	rsync --exclude=server/node_modules -avz -e ssh --progress * $(PI_SSH):$(PI_DIR)/

	# Run deploy script
	ssh $(PI_SSH) 'cd $(PI_DIR); ./deploy.sh'
